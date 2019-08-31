#include <bits/stdc++.h>
#define hi                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define vi vector<int>
typedef long long ll;
using namespace std;
int main()
{
    hi;
    int n;
    vi a(50);
    ll dp[n][n];
    rep(i, 0, n) cin >> a[i], dp[i][i] = 0, dp[i][i + 1] = 0;
    for (int r = 1; r < n; r++)
    {
        for (int l = r - 2; l >= 0; l--)
        {
            ll mn = 1000000000;
            for (int k = r - 1; k > l; k--)
            {
                mn = min(mn, dp[l][k] + dp[k][r] + (a[r] * a[k] * a[l]));
            }
            dp[l][r] = mn;
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}
