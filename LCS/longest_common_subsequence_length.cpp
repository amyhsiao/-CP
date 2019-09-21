int main()
{
    hi;
    string a, b;
    while (cin >> a >> b)
    {
        int n = a.size(), m = b.size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        rep(i, 1, n + 1)
        {
            rep(j, 1, m + 1)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] += dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[n][m] << '\n';
    }
    return 0;
}
