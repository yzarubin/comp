#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;

    vector<vector<int>> g(n);
    vector<int> tired(n);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        tired[i] = !b;
        g[a].push_back(i);
    }

    int ans = 0;

    function<void(int, int)> go = [&](int to, int from) {
        for (auto v : g[to]) go(v, to);

        bool flag = false;
        for (auto v : g[to]) {
            if (tired[v]) flag = true;
        }

        if (flag) {
            for (auto v : g[to]) tired[v] = 0;
            if (from != -1) tired[from] = 0;
            tired[to] = 0;
            ans++;
        }
    };

    go(0, -1);
    cout << ans;
    
    return 0;
}
