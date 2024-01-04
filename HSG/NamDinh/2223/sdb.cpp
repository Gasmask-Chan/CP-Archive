#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<bool> p(1000001, true);
vector<int> f;
void sieve(int n = 1e6)
{
    p[0] = p[1] = false;
    for (int i = 2; i <= n; i++)
        if (p[i])
        {
            f.push_back(i * i);
            if (i * i <= n) for (int j = i * i; j <= n; j += i) p[j] = false;
        }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("SDB.INP", "r", stdin); freopen("SDB.OUT", "w", stdout);
    int t;
    cin >> t;
    sieve();
    while (t--)
    {
        int a;
        cin >> a;
        cout << *lower_bound(f.begin(), f.end(), a) << ' ';
    }
    return 0;
}
