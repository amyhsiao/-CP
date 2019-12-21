#include <bits/stdc++.h>
#define hi ios_base::sync_with_stdio(0), cin.tie(0);
#define pb push_back
#define emb emplace_back
#define int long long
using namespace std;
int deep[100005], par[100005], up[100005][20], cost[100005][20], n, l;
struct edge
{
    int a, b, w;
    bool operator<(const edge &other) { return w < other.w; }
} g[500005];
struct E
{
    int b, w;
};
vector<int> v;
vector<E> t[100005];
int f(int x) { return ((x == par[x]) ? x : par[x] = f(par[x])); }
void u(int x, int y) { par[f(x)] = f(y); }
void dfs(int v, int p, int d, int w)
{
    deep[v] = d, up[v][0] = p, cost[v][0] = w;
    for (E i : t[v])
        if (i.b != p)
            dfs(i.b, v, d + 1, i.w);
}
void init()
{
    l = ceil(log2(n)) + 1;
    for (int j = 1; j < l; j++)
        for (int i = 1; i <= n; i++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
            cost[i][j] = max(cost[i][j - 1], cost[up[i][j - 1]][j - 1]);
        }
}
int lca(int a, int b)
{
    if (deep[a] < deep[b])
        swap(a, b);
    int p = deep[a] - deep[b], ans = -2147483647;
    for (int i = 0; p; i++)
    {
        if (p & 1)
            ans = max(ans, cost[a][i]), a = up[a][i];
        p >>= 1;
    }
    if (a == b)
        return ans;
    for (int i = l - 1; i >= 0; i--)
        if (up[a][i] != up[b][i])
            ans = max({ans, cost[a][i], cost[b][i]}), a = up[a][i], b = up[b][i];
    return max({ans, cost[a][0], cost[b][0]});
}

main()
{
    hi;
    int m, mst;
    cin >> n >> m;
    v.clear();
    mst = 0;
    for (int i = 0; i <= n; i++)
        par[i] = i, t[i].clear();
    for (int i = 0; i < m; i++)
        cin >> g[i].a >> g[i].b >> g[i].w;
    sort(g, g + m);
    for (int i = 0; i < m; i++)
    {
        if (f(g[i].a) != f(g[i].b))
        {
            u(g[i].a, g[i].b);
            mst += g[i].w;
            t[g[i].a].pb(E{g[i].b, g[i].w});
            t[g[i].b].pb(E{g[i].a, g[i].w});
        }
        else
            v.emb(i);
    }
    dfs(1, 1, 0, 0);
    init();
    int ans = 2147483647;
    for (int i : v)
    {
        int w = lca(g[i].a, g[i].b);
        ans = min(ans, g[i].w - w);
    }
    cout << mst << ' ' << mst + ans << '\n';
}

//sampled from https://tnlolicon.blogspot.com/2019/03/zj-c495.html?fbclid=IwAR1eW4E7FT6d0KwbmeZjXSQci4jikqKpfr2A9rJTPW87aatSut-OWvMFNgk