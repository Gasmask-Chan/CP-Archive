#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 1007

int n, m, f[MAX][MAX];

int getsum(int x, int y, int u, int v)
{
    return f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1];
}

bool isequal(int x, int y, int z)
{
    return x == y && x == z;
}

bool ok()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i - 1 > 0 && j < m && isequal(getsum(i, 1, n, j), getsum(1, 1, i - 1, m), getsum(i, j + 1, n, m)))
            {
                cout << "YES\n";
                cout << "N " << i - 1 << '\n';
                cout << "D " << j;
                return true;
            }

            if (i < n && j < m && isequal(getsum(1, 1, i, j), getsum(1, j + 1, n, m), getsum(i + 1, 1, n, j)))
            {
                cout << "YES\n";
                cout << "D " << j << '\n';
                cout << "N " << i;
                return true;
            }

            if (i < n && j < m && isequal(getsum(1, 1, i, j), getsum(i + 1, 1, n, m), getsum(1, j + 1, i, m)))
            {
                cout << "YES\n";
                cout << "N " << i << '\n';
                cout << "D " << j;
                return true;
            }

            if (j - 1 > 0 && i < n && isequal(getsum(1, j, i, m), getsum(1, 1, n, j - 1), getsum(i + 1, j, n, m)))
            {
                cout << "YES\n";
                cout << "D " << j - 1 << '\n';
                cout << "N " << i;
                return true;
            }
        }

    for (int sl, i = 1; i < m; i++)
    {
        sl = f[n][m] - f[n][i];
        for (int j = 1; j < i; j++)
            if (f[n][j] == sl && f[n][i] - f[n][j] == sl)
            {
                cout << "YES\n";
                cout << "D " << j << '\n';
                cout << "D " << i;
                return true;
            }
    }

    for (int sb, i = 1; i < n; i++)
    {
        sb = getsum(i + 1, 1, n, m);
        for (int j = 1; j < i; j++)
            if (getsum(1, 1, j, m) == sb && getsum(j + 1, 1, i, m) == sb)
            {
                cout << "YES\n";
                cout << "N " << j << '\n';
                cout << "N " << i;
                return true;
            }
    }

    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("dowry.inp", "r", stdin); freopen("dowry.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> f[i][j];
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }

    if (!ok()) cout << "NO";
    return 0;
}
