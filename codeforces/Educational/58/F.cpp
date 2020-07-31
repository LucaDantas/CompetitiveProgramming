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
void debug() { cerr << '\n'; }
template<typename Ini, typename... Fim> void debug(Ini I, Fim... F) { cerr << " " << I; debug(F...); }
#define db(...) cerr << "DEBUG (" << #__VA_ARGS__ << ") ==", debug(__VA_ARGS__)
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

constexpr ll inf = 1e18L;
constexpr int maxn = 1e5 + 10;
constexpr int mod = 1000000007;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count() ^ (long long) (make_unique<char>().get()));

int n, m;
vi a, s, f, c, r;

bool check(ll v, int i) {
	ll gasosa = v;
	int R = r[i];
	rep(j,s[i]-1,f[i]-1) {
		if(1ll*(a[j+1] - a[j])*c[i] > v) return 0;
		if(1ll*(a[j+1] - a[j])*c[i] > gasosa) gasosa = v, R--;
		gasosa -= 1ll*(a[j+1] - a[j])*c[i];
	}
	if(R < 0) return 0;
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	
	a.resize(n);
	s.resize(m);
	f.resize(m);
	c.resize(m);
	r.resize(m);

	rep(i,0,n) scanf("%d", &a[i]);
	rep(i,0,m) scanf("%d %d %d %d", &s[i], &f[i], &c[i], &r[i]);
	
	vi ord(m); rep(i,0,m) ord[i] = i;
	shuffle(all(ord), rng);

	ll now = 0;
	rep(i,0,m) {
		if(check(now, ord[i])) continue;
		ll L = now, R = inf;
		while(L <= R) {
			ll M = (L+R) >> 1;
			if(check(M, ord[i])) now = M, R = M - 1;
			else L = M + 1;
		}
	}
	printf("%lld\n", now);
}
