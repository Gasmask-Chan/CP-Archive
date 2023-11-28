#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 3000001

int cnt[MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cappt.inp", "r", stdin); freopen("cappt.out", "w", stdout);
    int n, k, ans = 0;
    cin >> n >> k;
    for (int x, i = 1; i <= n; i++)
    {
        cin >> x;
        if (k >= x) ans += cnt[k - x];
        cnt[x]++;
    }

    cout << ans;
    return 0;
}
