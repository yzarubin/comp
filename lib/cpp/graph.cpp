// Turan
// # of edges for T(n,r)
ll turan(ll n, ll r) {
    return (r - 1) * pow(n, 2) / (2 * r);
}


// LCA
void precalc_lca(int node, int N, int sqrt_height)  {
  if (level[node] < sqrt_height) 
    lca[node] = 1;
  else {
    if (!(level[node] % sqrt_height))
      lca[node] = parent[node];
    else
      lca[node] = lca[parent[node]];
  }

  for (auto &k : children[node]) {
    precalc_lca(k, N, sqrt_height);
  }
}

int LCA(vi &parent, vi &lca, vi &level, int x, int y) {
  while (lca[x] != lca[y])
    if (level[x] > level[y])
      x = lca[x];
    else
      y = lca[y];
         
  while (x != y)
    if (level[x] > level[y])
      x = parent[x];
    else
      y = parent[y];

  return x;
}


// Floyd Warshall
for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            G[i][j] = min(G[i][j], G[i][k] + G[k][j]);




// Tarjan's algorithm + topological sort
struct SCC {
  vector<vector<int>> graph;
  int index;
  vector<int> idx;
  vector<int> lowlink;
  vector<bool> onstack;
  stack<int> stk;
  vector<int> sccidx;
  int scccnt;
  vector<int> topo;
  
  void init(int n) {
    graph.clear();
    graph.resize(n);
    idx.assign(n, -1);
    index = 0;
    onstack.assign(n, 0);
    lowlink.assign(n, (int)1e9);
    stk.clear();
    sccidx.assign(n, -1);
    scccnt = 0;

  }
  
  //u -> v
  void addedge(int u, int v) {
    graph[u].push_back(v);
  }
  
  void dfs(int u) {
    idx[u] = index;
    lowlink[u] = index;
    index++;
    stk.push(u);
    onstack[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if (idx[v] == -1) {
        dfs(v);
        lowlink[u] = min(lowlink[u], lowlink[v]);
      } else if (onstack[v]) {
        lowlink[u] = min(lowlink[u], idx[v]);
      }
    }

    if (lowlink[u] == idx[u]) {
      while (true) {
        int v = stk.top();
        stk.pop();
        onstack[v] = false;
        sccidx[v] = scccnt;
        if (v == u) break;
      }
      scccnt++;
    }
  }
  
  void tarjan() {
    for (int i = 0; i < graph.size(); i++) {
      if (idx[i] == -1) {
        dfs(i);
      }
    }
  }

  void topological_sort() {
    tarjan();
    int n = graph.size();
    topo.resize(n);
    vector<pair<int,int>> tmp;
    for (int i = 0; i < n; i++) tmp.push_back({sccidx[i], i});

    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());

    for (int i = 0; i < n; i++) {
      topo[i] = tmp[i].second;
      if (i > 0) assert(tmp[i].first != tmp[i - 1].first);
    }
  }
};