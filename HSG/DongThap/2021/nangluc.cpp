#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100001

int a[MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("nangluc.inp", "r", stdin); freopen("nangluc.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = -1;
    for (int l = 0, sum = 0, r = 0; r < n; r++)
    {
        sum += a[r];
        while (sum >= k && l <= r)
        {
            ans = max(ans, sum / (r - l + 1));
            sum -= a[l++];
        }
    }

    cout << ans;
    return 0;
}
