#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 1000001

int ans = -1;
vector<int> g[MAX];
bool visited[MAX];

void dfs(int u)
{
    ans++;
    visited[u] = true;
    for (int &v : g[u]) if (!visited[v]) dfs(v);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ketban.inp", "r", stdin); freopen("ketban.out", "w", stdout);
    int n, k, m;
    cin >> n >> k >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(k);
    cout << ans;
    return 0;
}
