#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 201

int cost[MAX][MAX], f[MAX][MAX], trace[MAX][MAX], ans[MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("messages.inp", "r", stdin); freopen("messages.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> cost[i][j];

    for (int j = 1; j <= n; j++) f[1][j] = cost[j][1], trace[1][j] = j;

    for (int i = 2; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= j; k++)
            {
                if (f[i - 1][j - k] + cost[k][i] < f[i][j])
                {
                    f[i][j] = f[i - 1][j - k] + cost[k][i];
                    trace[i][j] = k;
                }
            }
        }

    cout << f[m][n] << '\n';
    int cur = trace[m][n], re = n, pos = m;
    while (pos)
    {
        ans[pos] = cur;
        re -= cur;
        cur = trace[--pos][re];
    }

    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
    return 0;
}
