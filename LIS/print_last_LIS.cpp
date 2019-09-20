//using a varition of Robinson-Schensted-Knuth Algorithm
#include <bits/stdc++.h>
#define hi ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb emplace_back
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
using namespace std;
int main()
{
    hi;
    int a, t;
    vector<int> v, cnt, vec;
    cin >> a;
    t = a;
    v.pb(a), vec.pb(a), cnt.pb(1);
    while (cin >> a)
    {
        vec.pb(a);
        if (a > v.back())
            v.pb(a), cnt.pb(v.size());
        else
        {
            cnt.pb(lower_bound(v.begin(), v.end(), a) - v.begin() + 1);
            *lower_bound(v.begin(), v.end(), a) = a;
        }
    }
    cout << v.size() << "\n-\n";
    int c = v.size(), idx = v.size() - 1;
    for (int i = cnt.size() - 1; i > -1; i--)
    {
        if (cnt[i] == c)
            v[idx--] = vec[i], c--;
    }
    rep(i, 0, v.size()) cout << v[i] << '\n';
    return 0;
}
