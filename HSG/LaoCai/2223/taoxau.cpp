#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 3000001

string x;
deque<char> y;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("taoxau.inp", "r", stdin); freopen("taoxau.out", "w", stdout);
    cin >> x;
    for (int i = 0; i < x.size(); i++)
        i & 1 ? y.push_back(x[i]) : y.push_front(x[i]);

    if (y.size() & 1) for (auto i : y) cout << i;
    else for (int i = y.size() - 1; i >= 0; i--) cout << y[i];
    return 0;
}
