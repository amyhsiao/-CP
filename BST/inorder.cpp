#include <bits/stdc++.h>
#define for(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int arr[1000005];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  rep(i,0,n) cin>>arr[i];
  sort(arr,arr+n);
  rep(i,0,n) cout<<arr[i]<<' ';
  return 0;
}
