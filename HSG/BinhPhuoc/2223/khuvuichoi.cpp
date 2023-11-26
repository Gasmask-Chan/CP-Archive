#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100001

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("khuvuichoi.inp", "r", stdin); freopen("khuvuichoi.out", "w", stdout);
    int st, ed, ans = 0;
    cin >> st >> ed;
    for (int cnt = 1, i = st + 1; i <= ed; i++, cnt++)
    {
        if (cnt > 4) ans += i <= 12 ? 3 : 5;
        else ans += i <= 12 ? 6 : 10;
    }

    cout << ans;
    return 0;
}
