/*
Given an array of n integers, find for each array position the nearest position to its left having a smaller value.
*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int (i) = a; (i) < (b); (i)++ )
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



int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, x;

	cin>>n;

	stack<int> stk1;// x
	stack<int> stk2; // index

	rep(i, 0, n){
		cin>>x;		
		if(stk1.size() == 0){
			cout<<"0 ";
		}
		else{
			while(stk1.top() >= x){
				stk1.pop();
				stk2.pop();
				if(!stk1.size()) break;
			}
			
			if(stk1.size() == 0){
				cout<<"0 ";
			}
			else{
				cout<<stk2.top()<<' ';
			}
		}

		stk1.push(x);
		stk2.push(i+1);

	}

}
 
