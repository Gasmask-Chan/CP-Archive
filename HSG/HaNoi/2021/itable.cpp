#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX 5001

int ac[MAX][MAX], ar[MAX][MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("itable.inp", "r", stdin); freopen("itable.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    while (t--)
    {
        int k, rc, x, y;
        cin >> k >> rc >> x >> y;
        int mid = (x + y) >> 1;
        if (k == 1)
        {
            ar[rc][x]++;
            if (y + 2 <= n) ar[rc][y + 2]++;
            if ((y - x + 1) & 1)
            {
                if (mid + 1 <= n)
                    ar[rc][mid + 1] -= 2;
            }
            else
            {
                if (mid + 1 <= n) ar[rc][mid + 1]--;
                if (mid + 2 <= n) ar[rc][mid + 2]--;
            }
        }
        else
        {
            ac[x][rc]++;
            if (y + 2 <= n) ac[y + 2][rc]++;
            if ((y - x + 1) & 1)
            {
                if (mid + 1 <= n)
                    ac[mid + 1][rc] -= 2;
            }
            else
            {
                if (mid + 1 <= n) ac[mid + 1][rc]--;
                if (mid + 2 <= n) ac[mid + 2][rc]--;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            ar[i][j] += ar[i][j - 1];
            ac[i][j] += ac[i - 1][j];
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ar[i][j] += ar[i][j - 1], ac[i][j] += ac[i - 1][j];

    int q, x, y;
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        cout << ac[x][y] + ar[x][y] << '\n';
    }
    return 0;
}
