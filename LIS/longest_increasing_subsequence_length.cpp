//Robinson-Schensted-Knuth Algorithm
#include <bits/stdc++.h>
#define hi                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define pb emplace_back
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
int main()
{
    hi;
    int n, a; // an array with n integers
    cin >> n >> a;
    vector<int> v;
    v.pb(a); // get array[0]
    rep(i, 1, n) //get array[1] to array[n-1] while calculating at the same time
    {
        cin >> a;
        if (a > v.back())
            v.pb(a);
        else
            *lower_bound(v.begin(), v.end(), a) = a;
    }
    cout << v.size() << '\n';
    return 0;
}
