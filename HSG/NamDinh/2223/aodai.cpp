#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX 1001

int cnt[5];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("aodai.inp", "r", stdin); freopen("aodai.out", "w", stdout);
    int n;
    cin >> n;
    for (int x, i = 0; i < n; i++) cin >> x, cnt[x]++;

    int ans = cnt[4];
    if (cnt[3] >= cnt[1])
    {
        ans += cnt[1];
        cnt[3] -= cnt[1];
        cnt[1] = 0;
    }
    else
    {
        ans += cnt[3];
        cnt[1] -= cnt[3];
        cnt[3] = 0;
    }

    if (cnt[2] >= cnt[1])
    {
        ans += cnt[1] / 2 + cnt[1] % 2;
        cnt[2] -= cnt[1] / 2 + cnt[1] % 2;
        cnt[1] = 0;
    }
    else
    {
        while (cnt[1] > 0 && cnt[2] > 0)
        {
            if (cnt[1] >= 2)
            {
                ans++;
                cnt[1] -= 2;
                cnt[2]--;
            }
            else if (cnt[1] >= 1)
            {
                ans++;
                cnt[1]--;
                cnt[2]--;
            }
        }
    }

    if (cnt[1]) cnt[1] = cnt[1] / 4 + 1;
    if (cnt[2]) cnt[2] = cnt[2] / 2 + cnt[2] % 2;
    ans += cnt[1] + cnt[2] + cnt[3];

    cout << ans;
    return 0;
}
