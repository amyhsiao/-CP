int n, w;
vector<pii> a(n); //weight, value
rep(i, 0, n) cin >> a[i].F >> a[i].S;
int dp[w + 1] = {0};
for(int i = 0; i < n; i++)
{
  for (int j = a[i].F; j <= w; j++)
  {
    dp[j] = max(dp[j], dp[j - a[i].F] + a[i].S);
  }
}
cout << dp[w] << '\n';
