#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '['; string sep = ""; for (const auto &x : v) os << sep << x, sep = ", "; return os << ']'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A> ostream& operator<<(ostream &os, const set<A> &s) { os << '{'; string sep = ""; for (const auto &x : s) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << '{'; string sep = ""; for (const auto &x : m) os << sep << x.first << " -> " << x.second, sep = ", "; return os << '}'; }

#ifdef MY_DEBUG_FLAG
void debug() { cerr << endl; }
template<typename Ini, typename... Fim> void debug(Ini I, Fim... F) { cerr << I; if(sizeof...(F)) cerr << ", "; debug(F...);}
#define db(...) cerr << "DEBUG (" << #__VA_ARGS__ << ") == ", debug(__VA_ARGS__)
#else
#define db(...)
#endif

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false), cout.tie(nullptr), cin.tie(nullptr)
#define sz(a) ((int)(a).size())
#define rep(i,a,b) for(int i=(a); i<(b); i++)
#define dec(i,n,a) for(int i=(n); i>=(a); i--)
#define clr(a,v) memset(a, v, sizeof(a))
#define all(a) (a).begin(),(a).end()

constexpr int inf = 0x3f3f3f3f;
constexpr int maxn = 1e7 + 10;
constexpr int mod = 1000000007;

vector<int> pr;

int f[maxn];

void sieve() {
	for(int i = 2; i < maxn; i++) {
		if(!f[i]) {
			pr.pb(i);
			f[i] = i;
		}
		for(int j = 0; j < sz(pr) && pr[j] <= f[i] && 1ll * i * pr[j] < maxn; j++)
			f[i*pr[j]] = pr[j];
	}
}

void decomp(int& x) {
	map<int, int> ans;
	while(x > 1) {
		++ans[f[x]];
		x /= f[x];
	}
	for(auto it : ans)
		if(it.second&1)
			x *= it.first;
}

int cnt[maxn];

int main() {
	sieve();
	int t; scanf("%d", &t);
	while(t--) {
		int n, k; scanf("%d %d", &n, &k);
		vector<vector<int>> dp(n+1, vector<int>(k+1, inf)), lim(n+1, vector<int>(k+1));
		vector<int> a(n+1);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]), decomp(a[i]);
		for(int j = 0; j <= k; j++) {
			for(int i = n, ptr = n, usados = 0; i >= 1; i--) {
				while(ptr && usados + (cnt[a[ptr]] > 0) <= j) {
					usados += cnt[a[ptr]] > 0;
					++cnt[a[ptr]];
					--ptr;
				}
				lim[i][j] = ptr;
				--cnt[a[i]];
				usados -= cnt[a[i]] > 0;
			}
		}
		dp[0][0] = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j <= k; j++)
				for(int l = 0; l <= j; l++)
					dp[i][j] = min(dp[i][j], dp[lim[i][l]][j-l] + 1);
		}
		printf("%d\n", dp[n][k]);
	}
}
