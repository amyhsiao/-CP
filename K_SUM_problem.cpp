/*

This is a 4-SUM problem implementation. The rest are just the same: simpliy add another loop.

*/

#include <bits/stdc++.h>
#define rep(i, a, b) for(int (i)=a;(i)<(b);(i++))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define _sort(a) sort(a.begin(), a.end())
#define lowbit(x) (x)&(-x)
#define pii pair<int, int>
#define vi vector<int>
const unsigned int MOD = 1e9 + 7;
const long long INF = 1e12;
 
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<pair<ll, int>> a(5001);
int n;
ll x;
vector<int> twosum(int goalsum, int l, int r){
	vector<int> ret;
	ret.pb(a[l-1].S);
	rep(lp, l, r){
		int rp = r;
		while(a[lp].F + a[rp].F > goalsum && rp > lp){
			rp--;
		}
		if(a[lp].F+a[rp].F == goalsum && rp > lp) {
			ret.pb(a[lp].S);
			ret.pb(a[rp].S);
			break;
		}
		if(rp == lp){
			return ret;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin>>n>>x;

	rep(i, 0, n) {
		cin>>a[i].F;
		a[i].S = 1 + i;
	}

	sort(a.begin(), a.begin()+n);
	vector<int> res;
	rep(k, 0, n-3){
		rep(i, k+1, n-2){
			res = twosum(x-a[i].F-a[k].F, i+1, n-1);
			if(res.size() == 3){
				break;
			}
		}
		if(res.size() == 3){
			res.pb(a[k].S);
			break;
		}
	}
	if(res.size() != 4) cout<<"IMPOSSIBLE";
	else{
		sort(res.begin(), res.end());
		rep(i, 0, res.size()) cout<<res[i]<<' ';
	}
}
 
