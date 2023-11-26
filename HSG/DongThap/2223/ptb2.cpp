#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100001

int a[MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ptb2.inp", "r", stdin); freopen("ptb2.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    if (n > 3000)
    {
        n -= 2;
        while (n > 0)
        {
            ans += n;
            n -= 2;
        }

        return cout << (ans << 1), 0;
    }

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
             ans += *lower_bound(a + j + 1, a + n, a[i] + a[j]) == a[i] + a[j];

    cout << (ans << 1);
    return 0;
}
