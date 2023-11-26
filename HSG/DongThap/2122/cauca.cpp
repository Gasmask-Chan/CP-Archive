#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 70

int cost[MAX], val[MAX], niga[MAX], f[MAX][60 * MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cauca.inp", "r", stdin); freopen("cauca.out", "w", stdout);
    int n, h;
    cin >> n >> h;
    h *= 60;
    for (int i = 1; i < n; i++) cin >> cost[i];
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i <= n; i++) cin >> niga[i];

    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;

    int ans = -1e18;
    for (int total = 0, i = 1; i <= n; i++)
    {
        for (int j = total + 1; j <= h; j++)
        {
            f[i][j] = f[i - 1][j];
            for (int sum = val[i], v = val[i], z = 5; z <= j - total; z += 5)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - z - cost[i - 1]] + sum);
                v = max(v - niga[i], 0LL);
                sum += v;
            }
            ans = max(ans, f[i][j]);
        }

        total += cost[i];
    }

    cout << ans;
    return 0;
}
