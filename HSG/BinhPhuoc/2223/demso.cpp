#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 501

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("demso.inp", "r", stdin); freopen("demso.out", "w", stdout);
    int l, r, c;
    cin >> l >> r >> c;
    int total = (r / c) - ((l - 1) / c);
    cout << r - l + 1 - total;
    return 0;
}
