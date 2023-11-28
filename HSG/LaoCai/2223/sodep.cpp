#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100001

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sodep.inp", "r", stdin); freopen("sodep.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            ans++;
            if (n / i != i) ans++;
        }

    cout << ans;
    return 0;
}
