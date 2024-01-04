#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sodep.inp", "r", stdin); freopen("sodep.out", "w", stdout);
    int n;
    cin >> n;
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    cout << ((sum % 10) == 9);
    return 0;
}
