#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 2007

int a[MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tdoan.inp", "r", stdin); freopen("tdoan.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = 1e9, cnt = 1e9;
    for (int sum, i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = i; j <= n; j++)
        {
            sum += a[j];
            if (sum > k) break;
            if (sum == k)
            {
                if (j - i + 1 < cnt)
                {
                    l = i;
                    cnt = j - i + 1;
                }
            }
        }
    }

    if (cnt == 1e9) cout << 0;
    else cout << l << ' ' << cnt;
    return 0;
}
