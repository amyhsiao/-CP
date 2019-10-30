#include <bits/stdc++.h>
#define N 105
#define K 6 // k >= log2(N)+1  
using namespace std;
int lg[N+1]; // log
int a[N+1]; // array
int st[N+1][K+1]; // sparse table
void c(){
  lg[1]=0;
  for(int i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;

  for(int j = 1; j <= K; j++)
    for(int i = 0;i + (1 << j) <= N; i++)
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int q(int l, int r){
  int j = lg[r - l + 1];
  return min(st[l][j], st[r - (1 << j) + 1][j]);
}
