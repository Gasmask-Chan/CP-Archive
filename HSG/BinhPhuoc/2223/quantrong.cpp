#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 500007

int a[MAX], pf[MAX], posi[MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("quantrong.inp", "r", stdin); freopen("quantrong.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pf[i] = pf[i - 1] + a[i];

    int ans = 0;
    for (int j, i = 1; i <= n; i++)
    {
        j = posi[a[i]];
        if (j > 0) ans = max(ans, pf[i] - pf[j - 1]);
        if (!posi[a[i]]) posi[a[i]] = i;
    }

    cout << ans;
    return 0;
}
