#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100007

bool visited[MAX];
vector<int> g[MAX];

void dfs(int u)
{
    visited[u] = true;
    for (int v : g[u]) if (!visited[v]) dfs(v);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tinnhan.inp", "r", stdin); freopen("tinnhan.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) if (!visited[i]) ans++, dfs(i);

    cout << ans;
    return 0;
}
