#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 1007

int f[MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("chiamang.inp", "r", stdin); freopen("chiamang.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i], f[i] += f[i - 1];
    for (int i = 1; i <= n; i++) if (f[i] == f[n] - f[i]) return cout << i, 0;
    cout << 0;
    return 0;
}
