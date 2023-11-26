#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 3000002

int ans, sumdiv[MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sodacbiet.inp", "r", stdin); freopen("sodacbiet.out", "w", stdout);
    int l, r;
    cin >> l >> r;
    for (int i = 1; i <= r; i++)
        for (int j = i * 2; j <= r; j += i)
            sumdiv[j] += i;

    for (int i = l; i <= r; i++) ans += sumdiv[i] > i;

    cout << ans;
    return 0;
}
