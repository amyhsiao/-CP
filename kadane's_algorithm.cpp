int main()
{
    hi;
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int t = a[0], r = 1, res = -10000;
    while (r < n)
    {
        t = max(t + a[r], a[r]);
        res = max(t, res);
        r++;
    }
    cout << res << '\n';
    return 0;
}
