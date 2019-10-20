#include <bits/stdc++.h>
#define hi ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb emplace_back
#define vi vector<int>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
bitset<40010> vis;
bitset<40010> color;
void bipartite_graph()
{
    hi;
    int n, m; //nodes, edges
    cin >> n >> m;
    vis = 0;
    color = 0;
    vector<vi> e(n + 1); //edges

    //get graph
    int a, b;
    rep(i, 0, m)
    {
        cin >> a >> b;
        e[a].pb(b), e[b].pb(a);
    }

    int res = 1;
    //bfs
    queue<int> q;
    for (int k = 1; k <= n; k++)
    {
        if (!vis[k])
        {
            q.push(k);
            vis[k] = 1;
            color[k] = 1;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (int i : e[v])
                    if (!vis[i])
                        q.push(i), color[i] = !color[v], vis[i] = 1;
                    else if (color[i] == color[v])
                    {
                        res = 0;
                        break;
                    }
            }
            if (!res)
                break;
        }
        if (!res)
            break;
    }
    cout << ((res) ? "Yes" : "No") << '\n';
}
