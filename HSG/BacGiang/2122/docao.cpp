#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 1000005

int sumd(int x)
{
    int res = 0;
    while (x)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

bitset<MAX> p;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("docao.inp", "r", stdin); freopen("docao.out", "w", stdout);
    int n, h, ans = 0;
    cin >> n >> h;

    p.set();
    p[0] = p[1] = false;
    int sq = sqrt(n);
    for (int i = 2; i <= n; i++)
        if (p[i])
        {
            if (sumd(i) == h)
            {
                cout << i << '\n';
                ans++;
            }
            if (i > sq) continue;
            for (int j = i * i; j <= n; j += i) p[j] = false;
        }

    cout << ans;
    return 0;
}
