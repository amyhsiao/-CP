#include <bits/stdc++.h>
#define pb push_back
using namespace std;
struct edge
{
    int u, v, w; // 1 <= u, v <= n
    bool operator<(edge const &other) { return w < other.w; }
};
int n, m, cost;
vector<edge> e;
vector<int> par, r;
int find(int x) { return ((par[x] == x) ? x : (par[x] = find(par[x]))); }
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return;
    if (r[x] < r[y])
        par[x] = y;
    else
        par[y] = x, r[x] += ((r[x] == r[y]) ? 1 : 0);
}
void mst()
{
    par.resize(n + 1);
    r.resize(n + 1);
    for (int i = 0; i <= n; i++)
        par[i] = i, r[i] = 0;
    sort(e.begin(), e.end());
    for (edge E : e)
    {
        if (find(E.u) != find(E.v))
        {
            cost += E.w;
            unite(E.u, E.v);
        }
    }
}