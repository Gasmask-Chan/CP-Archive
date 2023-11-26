#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100007

int n;
int a[MAX];
bool f[21][MAX];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("atm.inp", "r", stdin); freopen("atm.out", "w", stdout);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    f[0][0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < MAX; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= a[i]) f[i][j] |= f[i - 1][j - a[i]];
        }

    int ans = 0;
    while (m--)
    {
        int x;
        cin >> x;
        ans += f[n][x];
    }

    cout << ans;
    return 0;
}
