#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 5001

int cnt[MAX];
vector<int> ans;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("vote.inp", "r", stdin); freopen("vote.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            cnt[j] += c == 'X';
        }
    }

    int best = 0;
    for (int i = 0; i < n; i++) best = max(best, cnt[i]);
    for (int i = 0; i < n; i++) if (cnt[i] == best) ans.push_back(i + 1);

    cout << ans.size() << ' ' << best << '\n';
    for (int &i : ans) cout << i << ' ';
    return 0;
}
