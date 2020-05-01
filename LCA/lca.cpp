#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

vector<vector<int>> adj, up;
vector<int> tin, tout, deep;
int n, l, t, root;

bool is_ac(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; };
bool distance(int u, int v, int a) { return deep[u] + deep[v] - 2 * deep[a]; }; //u, v, lca(u, v)

void dfs(int v, int p)
{
    tin[v] = ++t;
    up[v][0] = p;
    for (int i = 1; i <= l; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (auto u : adj[v])
        if (u != p)
            deep[u] = deep[v] + 1, dfs(u, v);
    tout[v] = ++t;
}

int lca(int u, int v)
{
    if (is_ac(u, v))
        return u;
    if (is_ac(v, u))
        return v;
    for (int i = l; i >= 0; i--)
        if (!is_ac(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

void init()
{
    deep[root] = 0;
    t = 0;
    l = ceil(log2(n));
    tin.resize(n + 1), tout.resize(n + 1), deep.resize(n + 1);
    up.resize(n + 1, vector<int>(l + 1));
    dfs(root, root);
}

void read() {}
