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
#define clr(a,v) memset(a, v, sizeof(a))
#define all(a) (a).begin(),(a).end()
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define max3(x, y, z) max(x, max(y, z))
#define db(x) cerr << #x << " == " << x << endl
#define _ << " " <<

const int maxn = 1e5 + 100;
const string bad = "IMPOSSIBLE";
const char d[] = {'E', 'W', 'N', 'S'};
const int mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};
string ans = "";

void solve(){
	int x,y, i=0;
	cin >> x >> y;
	if((x+y)%2==0){
		cout << bad << endl;
		return;
	}
	while(i++ < 10){
		rep(k, 0, 4){
			if(mp(mx[k], my[k]) == mp(x,y)){
				ans.pb(d[k]);
				cout << "OI";
				return;
			}
		}
		rep(k, 0, 4){
			int dx = x - mx[k], dy = y - my[k];
			if((dx)%2 == 0 && (dy)%2 == 0 && ((dx+dy)/2)%2==1){
				ans.pb(d[k]);
				x = dx/2;
				y = dy/2;
			}
		}
		//if(x%2==1){
			//if((((x+1)/2)+y)%2 == 1){
				//x = (x+1)/2;
				//y /= 2;
			//}
			//else{
				//x = (x-1)/2;
				//y /= 2;
			//}
		//}
		//else{
			//if((((y+1)/2)+x)%2 == 1){
				//y = (y+1)/2;
				//x /= 2;
			//}
			//else{
				//y = (y-1)/2;
				//x /= 2;
			//}
		//}
	}
}

int main(){
	FAST;
	int t;
	cin >> t;
	rep(tt, 1, t+1){
		cout << "Case #" << tt << ": ";
		solve();
		cout << ans << endl;
		ans = "";
	}
}