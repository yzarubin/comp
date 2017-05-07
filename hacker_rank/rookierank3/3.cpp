#include <bits/stdc++.h>

using namespace std;

unordered_set<int> visited;
vector<vector<int>> g(100005);
int dfs(int u) {
    if (visited.count(u)) return 0;
    visited.insert(u);
    int ans = 1;
    for (auto i : g[u]) ans += dfs(i);
    return ans;
}

int main() {
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) ans = max(ans, dfs(i));
    
    cout << ans << endl;
    
    return 0;
}
