int main()
{
    hi;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int res = a[0], l = 0, r = 1, m = -10000;
    while (r < n)
    {
        res += a[r];
        if (a[r] > res)
        {
            res = a[r];
            l = r;
        }
        r++;
        m = max(m, res);
    }
    cout << m << '\n';
    return 0;
}
