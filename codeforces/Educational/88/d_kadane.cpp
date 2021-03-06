#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(a) ((int)(a).size())
#define rep(i,a,b) for(int i=(a); i<(b); i++)
#define trav(it, a) for(auto& it : a)
#define allin(it, a) for(auto it : a)
#define read(v, a, b) for(int i=(a); i<(b); i++) scanf("%d", &v[i]);
#define clr(a,v) memset(a, v, sizeof(a))
#define all(a) (a).begin(),(a).end()
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define db(x) cerr << #x << " == " << x << endl

const int maxn = 1e5 + 100, maxv = 40, inf = 0x3fffffff;

int main(){
	int n;
	scanf("%d", &n);
	vi a(n), now(n);
	read(a, 0, n);
	
	int ans = 0;
	
	rep(val,0,maxv) {
		rep(i,0,n) {
			now[i] = (a[i] > val)? -inf : a[i];
		}
		int v = 0;
		rep(i,0,n) {
			v += now[i];
			ans = max(ans, v - val);
			v = max(v, 0);
		}
	}
	
	printf("%d\n", ans);
}
