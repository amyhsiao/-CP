//prints valid solves in lexicographical order
#include <bits/stdc++.h>
#define hi                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
int m[9][9], cnt = 0;
vector<pii> pos; 
inline void _p();
inline void solve(int n);
inline int safe(int r, int c, int n);
int main()
{
    hi;
    //reads input
    rep(i, 0, 9)
    {
        rep(j, 0, 9)
        {
            cin >> m[i][j];
            if (m[i][j] == 0)
                pos.pb(mp(i, j));
        }
    }
    //solve the 0'th position to be solved
    solve(0);
    cout << "there are a total of " << cnt << " solution(s). ";
    return 0;
}
inline void _p()
{
    rep(i, 0, 9)
    {
        rep(j, 0, 8)
        {
            cout << m[i][j] << ' ';
        }
        cout << m[i][8] << '\n';
    }
    cout << '\n';
}
inline void solve(int n)
{
    int t = 0;
    if (n == pos.size())
    {
        _p();
        cnt++;
        return;
    }
    rep(i, 1, 10)
    {
        if (safe(pos[n].F, pos[n].S, i))
        {
            m[pos[n].F][pos[n].S] = i;
            solve(n + 1);
            m[pos[n].F][pos[n].S] = 0;
        }
    }
}
inline int safe(int r, int c, int n)
{
    int i, j;
    for (i = c - 1; i > -1; i--)
    {
        if (m[r][i] == n)
            return 0;
    }
    for (i = c + 1; i < 9; i++)
    {
        if (m[r][i] == n)
            return 0;
    }
    for (i = r - 1; i > -1; i--)
    {
        if (m[i][c] == n)
            return 0;
    }
    for (i = r + 1; i < 9; i++)
    {
        if (m[i][c] == n)
            return 0;
    }
    r /= 3;
    c /= 3;
    for (i = r * 3; i < (r + 1) * 3; i++)
    {
        for (j = c * 3; j < (c + 1) * 3; j++)
        {
            if (m[i][j] == n)
            {
                return 0;
            }
        }
    }
    return 1;
}
