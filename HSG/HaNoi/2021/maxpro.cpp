#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 5001

int multi(int a, int b, int MOD)
{
    if (a < 0 && b < 0) a = -a, b = -b;
    if (b < 0) swap(a, b);
    int res = 0;
    a = (a + MOD) % MOD;
    while (b)
    {
        if (b & 1) res = (res + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return res;
}

vector<int> ne,po;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("maxpro.inp", "r", stdin); freopen("maxpro.out", "w", stdout);
    int m;
    for (int x, i = 0; i < 3; i++)
    {
        cin >> x;
        if (x < 0) ne.push_back(x);
        else po.push_back(x);
    }
    cin >> m;

    sort(ne.begin(), ne.end());
    sort(po.begin(), po.end());
    if (ne.size() == 2 || ne.size() == 3) return cout << multi(ne[0], ne[1], m), 0;
    cout << multi(po[po.size() - 1], po[po.size() - 2], m);
    return 0;
}
