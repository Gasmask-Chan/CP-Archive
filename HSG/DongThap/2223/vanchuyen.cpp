#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100001

int f[MAX];
vector<pair<int, int>> g[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("vanchuyen.inp", "r", stdin); freopen("vanchuyen.out", "w", stdout);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    memset(f, 0x3f, sizeof f);
    f[s] = 0;
    q.emplace(0, s);
    while (!q.empty())
    {
        int u, w;
        tie(w, u) = q.top();
        q.pop();

        if (f[u] != w) continue;
        for (auto [v, c] : g[u])
            if (f[u] + c < f[v])
            {
                f[v] = f[u] + c;
                q.emplace(f[v], v);
            }
    }

    cout << f[t];
    return 0;
}
