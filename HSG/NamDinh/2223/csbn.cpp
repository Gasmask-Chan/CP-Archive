#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX 10000001

string s, cur;
int n, id;
ll ans;
int a[MAX];

int convert(string &x)
{
    int res = 0;
    for (auto c : x) res = res * 10 + (c - '0');
    return res;
}

unordered_map<int, int> mp;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("csbn.inp", "r", stdin); freopen("csbn.out", "w", stdout);
    cin >> n;
    cin.ignore();
    getline(cin, s);
    s.push_back(' ');
    for (auto c : s)
    {
        if (c == ' ')
        {
            a[id] = convert(cur);
            cur = "";
            id++;
        }
        else cur.push_back(c);
    }


    for (int i = n - 1; i >= 0; i--)
        ans += ++mp[a[i]] - 1;

    cout << ans;
    return 0;
}
