#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define endl '\n'
#define f first
#define s second
#define sz(a) ((int)(a).size())
#define rep(i,a,b) for(int i=(a); i<(b); i++)
#define dec(i,n,a) for(int i=(n); i>=(a); i--)
#define read(v, a, b) for(int i=(a); i<(b); i++) cin>>v[i]
#define printv(v, a, b) for(int i=(a); i < (b); i++) cout << v[i] << ' '
#define clr(a,v) memset(a, v, sizeof(a))
#define all(a) (a).begin(),(a).end()
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define max3(x, y, z) max(x, max(y, z))
#define db(x) cerr << #x << " == " << x << endl
#define _ << " " <<

const int maxn = 2e5 + 100;
int a[maxn];

int main(){
	FAST;
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(n % 4 == 0){
			ll sum = 0, sum2 = 0;
			cout << "YES" << endl;
			for(ll i = 1LL; i <= n/2; i++){
				cout << (i<<1LL) << ' ';
				sum += (i<<1LL);
			}
			for(ll i = 1LL; i < n/2; i++){
				cout << (i<<1LL)-1LL << ' ';
				sum2 += (i<<1LL)-1LL;
			}
			cout << sum - sum2 << endl;
		}
		else cout << "NO" << endl;	
	}
}
