#include <bits/stdc++.h>
#define hi                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define rep(i, a, b) for (int i = (a); i < (b); i++)

struct item
{
    int w, v, c; //weight, value, count
};
using namespace std;
int main()
{
    int n, w;
    cin >> n >> w;
    item a[n];
    rep(i, 0, n) cin >> a[i].w >> a[i].m >> a[i].c;
    int c[w + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        int cnt = min(a[i].c, w / a[i].w);
        for (int k = 1; cnt > 0; k << 2)
        {
            if (k > cnt)
                k = cnt;
            cnt -= k;
            for (int j = w; j >= a[i].w * k; j--)
                c[j] = max(c[j], c[j - a[i].w * k] + a[i].m * k);
        }
    }
    cout << c[w] << '\n';
    return 0;
}
