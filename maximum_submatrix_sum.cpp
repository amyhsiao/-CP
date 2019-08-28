//2d kadane's algorithm
#define SIZE 502
int n;
ll a[SIZE][SIZE];
ll kadane_1d(ll arr[])
{
    ll ret = -1e9, t = arr[0];
    rep(i, 1, n)
    {
        t = max(arr[i], t + arr[i]);
        ret = max(ret, t);
    }
    return ret;
}
ll kadane_2d()
{
    ll ret = -1e9;
    //sum of the i'th row
    ll t[n];
    //for every submatrix's leftmost column starts at col
    rep(col, 0, n)
    {
        //reset t so that the submatrix leftmost column starts at col
        memset(t, 0, sizeof(t));
        //submatrix starting at column col to n - 1
        rep(c, col, n)
        {
            //sum of i'th row starting from column col to column c
            rep(row, 0, n)
                t[row] += a[row][c];
            //see if any submatrix from column col to c has a sum larger than ret
            ret = max(ret, kadane_1d(t));
        }
    }
    return ret;
}
int main()
{
    hi;
    // an n*n matrix
    cin >> n;
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cin >> a[i][j];
        }
    }
    ll res = kadane_2d();
    cout << res << '\n';
    return 0;
}
