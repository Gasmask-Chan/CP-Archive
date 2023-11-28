#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 10000001

bool check(int n)
{
    int y = 0, x = n;
    while (x)
    {
        y = y * 10 + x % 10;
        x /= 10;
    }
    if (n != y) return false;

    int cnt = 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            cnt++;
            while (n % i == 0) n /= i;
        }

    if (n != 1) cnt++;
    return cnt >= 3;
}

int ans;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sdxdep.inp", "r", stdin); freopen("sdxdep.out", "w", stdout);
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) ans += check(i);

    cout << ans;
    return 0;
}
