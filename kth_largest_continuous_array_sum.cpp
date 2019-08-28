int n, k, m;
vector<int> s(20001, 0), S(20001, 0), a(20001);
//merge sort
int f(int l, int r)
{
    if (l >= r)
        return 0;
    vector<int> t;
    int mid = (l + r) >> 1;
    int cnt = 0;
    cnt += f(l, mid);
    cnt += f(mid + 1, r);
    //check if s[j] - s[i] > m, since s[mid+1:r+1] will be sorted, then there are (r - j + 1) continuous subarray sums larger than m
    rep(i, l, mid + 1)
    {
        int j = upper_bound(s.begin() + mid + 1, s.begin() + r + 1, s[i] + m) - s.begin();
        cnt += r - j + 1;
    }
    //merge
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (s[i] <= s[j])
            t.pb(s[i++]);
        else
            t.pb(s[j++]);
    }
    while (i <= mid)
        t.pb(s[i++]);
    while (j <= r)
        t.pb(s[j++]);
    for (int i = l; i <= r; i++)
        s[i] = t[k++];
    return cnt;
}
int main()
{
    hi;
    while (cin >> n >> k && (n || k))
    {
        rep(i, 0, n) cin >> a[i];
        S[0] = 0;
        rep(i, 0, n) S[i + 1] = S[i] + a[i];
        //binary search
        int l = n * (-10000) - 1, h = n * (10000);
        while (h - l > 1)
        {
            m = (h + l) >> 1;
            rep(i, 0, n + 1) s[i] = S[i];
            //if cnt is larger than or equals to k, increase guess 
            if (f(0, n) > k - 1)
                l = m;
            else
                h = m;
        }
        cout << h << '\n';
    }
    return 0;
}
