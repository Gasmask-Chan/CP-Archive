#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 1000005

int wish[MAX];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ghh.inp", "r", stdin); freopen("ghh.out", "w", stdout);
    for (int i = 1; i < MAX; i++)
        for (int j = i; j < MAX; j += i)
            wish[j] += i;

    int n;
    cin >> n;
    for (int x, i = 0; i < n; i++)
    {
        cin >> x;
        cout << (2 * x <= wish[x]) << '\n';
    }
    return 0;
}
