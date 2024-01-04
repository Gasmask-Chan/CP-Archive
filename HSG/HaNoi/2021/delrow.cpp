#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 5001

const int MOD = 1e9 + 9;
const int base = 29;

char a[MAX][MAX];
int hsh[MAX];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("delrow.inp", "r", stdin); freopen("delrow.out", "w", stdout);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = n; i > 1; i--)
    {
        unordered_set<int> s;
        for (int j = 1; j <= m; j++)
        {
            hsh[j] = (hsh[j] * base + a[i][j] - 'a' + 1) % MOD;
            s.insert(hsh[j]);
        }
        if (s.size() == m)
        {
            ans = i - 1;
            break;
        }
    }

    cout << ans;
    return 0;
}
