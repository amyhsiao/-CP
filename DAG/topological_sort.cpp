//assuming the graph's acyclic
#include <bits/stdc++.h>
#define emb emplace_back
using namespace std;

int n;
vector<vector<int>> e;
vector<bool> vis;
vector<int> ans;

void dfs(int v)
{
    vis[v] = 1;
    for (int u : e[v])
        if (!vis[u])
            dfs(u);
    ans.emb(v);
}

void tpsort()
{
    vis.resize(n, 0);
    ans.clear();
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i);
    reverse(ans.begin(), ans.end());
}