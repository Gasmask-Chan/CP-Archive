#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100001

map<int, int> mp;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("somayman.inp", "r", stdin); freopen("somayman.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    while (n--)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    while (t--)
    {
        int x;
        cin >> x;
        cout << mp[x] << '\n';
    }
    return 0;
}
