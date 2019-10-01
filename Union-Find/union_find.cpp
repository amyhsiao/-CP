#include <bits/stdc++.h>
#define MAX_N 100
int par[MAX_N];
int rank[MAX_N];

void init(int n)
{
    for (int i = 0; i < n; i++)
        par[i] = i, rank[i] = 0;
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (rank[x] < rank[y])
        par[x] = y;
    else
        par[y] = x, rank[x] += ((rank[x] == rank[y]) ? 1 : 0);
}