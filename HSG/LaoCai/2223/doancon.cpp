#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100001

int modulo(string a, int MOD)
{
    int res = 0;
    for (auto c : a) res = (res * 10 + c - 48) % MOD;
    return res;
}

int power(int a, int n, int MOD)
{
    int res = 1;
    a %= MOD;
    while (n)
    {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int a[MAX];
map<int, int> mp;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("doancon.inp", "r", stdin); freopen("doancon.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        a[i] = power(modulo(s, k), m, k);
    }

    int ans = 0;
    mp[0] = 1;
    for (int sum = 0, i = 1; i <= n; i++)
    {
        sum = (sum + a[i]) % k;
        ans += mp[sum];
        mp[sum]++;
    }

    cout << ans;
    return 0;
}
