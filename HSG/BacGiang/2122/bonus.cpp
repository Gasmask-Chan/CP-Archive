#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 1000005

int a[MAX], mxl[MAX], mxr[MAX], mil[MAX], mir[MAX];

stack<int> stmx, stmi;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bonus.inp", "r", stdin); freopen("bonus.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        while (!stmx.empty() && a[stmx.top()] < a[i]) stmx.pop();
        if (!stmx.empty()) mxl[i] = stmx.top() + 1;
        else mxl[i] = 1;
        stmx.push(i);

        while (!stmi.empty() && a[stmi.top()] > a[i]) stmi.pop();
        if (!stmi.empty()) mil[i] = stmi.top() + 1;
        else mil[i] = 1;
        stmi.push(i);
    }

    while (!stmx.empty()) stmx.pop();
    while (!stmi.empty()) stmi.pop();

    for (int i = n; i > 0; i--)
    {
        while (!stmx.empty() && a[stmx.top()] <= a[i]) stmx.pop();
        if (!stmx.empty()) mxr[i] = stmx.top() - 1;
        else mxr[i] = n;
        stmx.push(i);

        while (!stmi.empty() && a[stmi.top()] >= a[i]) stmi.pop();
        if (!stmi.empty()) mir[i] = stmi.top() - 1;
        else mir[i] = n;
        stmi.push(i);
    }

    int ans = 0;
    for (int L, R, i = 1; i <= n; i++)
    {
        L = mxl[i], R = mxr[i];
        ans += a[i] * (i - L + 1) * (R - i + 1);

        L = mil[i], R = mir[i];
        ans -= a[i] * (i - L + 1) * (R - i + 1);
    }

    cout << ans;
    return 0;
}
