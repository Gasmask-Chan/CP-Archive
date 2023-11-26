#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 1001

int v[MAX], w[MAX];
double f[MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("doanxe.inp", "r", stdin); freopen("doanxe.out", "w", stdout);
    int n, p, l;
    cin >> n >> p >> l;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++) f[i] = 1e18;

    for (int i = 1; i <= n; i++)
        for (int mi = v[i], weight = w[i], j = i; weight <= p && j > 0; weight += w[--j])
        {
            mi = min(mi, v[j]);
            f[i] = min(f[i], f[j - 1] + (double)l / (double)mi);
        }

    cout << fixed << setprecision(2) << f[n];
    return 0;
}
