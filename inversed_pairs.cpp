typedef long long ll;
using namespace std;
int n, a[100000];
ll _mergesort(int l, int r);
ll merge(int l, int m, int r);

ll _mergesort(int l, int r)
{
    int mid;
    ll c = 0;
    if (r > l)
    {
        mid = (l + r) >> 1;
        c += _mergesort(l, mid);
        c += _mergesort(mid + 1, r);
        c += merge(l, mid + 1, r);
    }
    return c;
}
ll merge(int l, int m, int r)
{
    int t[r - l + 1];
    int i, j, k;
    ll cnt = 0;
    i = l, j = m, k = 0;
    while ((i < m) && (j <= r))
    {
        if (a[i] <= a[j])
            t[k++] = a[i++];
        else
        {
            t[k++] = a[j++];
            cnt += (m - i);
        }
    }
    while (i < m)
        t[k++] = a[i++];
    while (j <= r)
        t[k++] = a[j++];
    k = 0;
    for (i = l; i <= r; i++)
        a[i] = t[k++];
    return cnt;
}
int main()
{
    hi;
    int count = 1;
    while (cin >> n && n)
    {
        cout << "Case #" << count++ << ": ";
        rep(i, 0, n) cin >> a[i];
        ll res = _mergesort(0, n - 1);
        cout << res << '\n';
    }
    return 0;
}
