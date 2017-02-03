

// Turan
// # of edges for T(n,r)
ll turan(ll n, ll r) {
  return (r - 1) * pow(n, 2) / (2 * r);
}


// Disjoint set

vector<int> parent;
vector<int> parent_rank;

int find_parent(int n) {
  if (parent[n] != n) parent[n] = find_parent(parent[n]);
  return parent[n];
}

void merge_nodes(int a, int b) {
  int parentA = find_parent(a);
  int parentB = find_parent(b);

  if (parentA == parentB) return;

  if (parent_rank[parentA] > parent_rank[parentB]) {
    parent[parentB] = parentA;
    parent_rank[parentA] += parent_rank[parentB];
  } else {
    parent[parentA] = parentB;
    parent_rank[parentB] += parent_rank[parentA];
  }
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

