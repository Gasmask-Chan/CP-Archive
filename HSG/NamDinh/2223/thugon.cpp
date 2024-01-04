#include <bits/stdc++.h>

using namespace std;
#define int long long

string convert(int n)
{
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("thugon.inp", "r", stdin); freopen("thugon.out", "w", stdout);
    string s;
    while (cin >> s)
    {
        s.push_back('#');
        string ans;
        char pre = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != pre)
            {
                if (cnt > 1) ans += convert(cnt);
                ans.push_back(pre);
                cnt = 1;
                pre = s[i];
            }
            else cnt++;
        }

        cout << ans << '\n';
    }

    return 0;
}
