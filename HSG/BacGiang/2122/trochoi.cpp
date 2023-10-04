#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 1000005

int a[MAX], b[MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("trochoi.inp", "r", stdin); freopen("trochoi.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = 1e18;
    sort(b, b + n);
    for (int j, i = 0; i < n; i++)
    {
        j = lower_bound(b, b + n, -a[i]) - b;
        if (j < n) ans = min(ans, abs(a[i] + b[j]));
        if (j > 0) ans = min(ans, abs(a[i] + b[--j]));
    }

    cout << ans;
    return 0;
}
