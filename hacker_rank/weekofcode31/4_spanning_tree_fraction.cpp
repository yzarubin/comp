#include <bits/stdc++.h>
using namespace std;
static const long long bs = 1000000007;
static const int INF = 0x3f3f3f3f; 
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;

#define REP(i, n) for (int i=0; i < (int)(n); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1)

void addmod(ll &a, ll b){a = (a + b); if (a >= bs) a -= bs;}
void mulmod(ll &a, ll b){a = (a * b) % bs;}
template<class T>inline void cmax(T &x, const T &y) {if (x < y) x = y;}
template<class T>inline void cmin(T &x, const T &y) {if (y < x) x = y;}


/*************SOLUTION*************/

struct Edge {
  int u;
  int v;
  int a;
  int b;
};


ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) a %= b;
    else b %= a;
  }
  return a + b;
}


int gk(int a, int b) {
  return (a << 15) | b;
}

int N, M; 
const int MAXN = 100005;
vector<unordered_map<int, unordered_map<int,int>>> G(MAXN);

bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];
vector<pii> bridges;
void IS_BRIDGE(int i, int j) {
  if (G[i][j].size()==1) {
    bridges.pb({i,j});
  }
}

void dfs (int v, int p = -1) {
  used[v] = true;
  tin[v] = fup[v] = timer++;
  for (auto &k : G[v]) {
    int to = k.first;
    if (to == p)  continue;
    if (used[to])
      fup[v] = min (fup[v], tin[to]);
    else {
      dfs (to, v);
      fup[v] = min (fup[v], fup[to]);
      if (fup[to] > tin[v])
          IS_BRIDGE(v,to);
    }
  }
}

void find_bridges() {
    timer = 0;
    for (int i = 0; i < N; ++i)
        used[i] = false;
    for (int i = 0; i < N; ++i)
        if (!used[i])
            dfs (i);
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

bool cmp(int ac, int bc, int a, int b,  int asum, int bsum ) {
  if (a == -1) return true;
  return (double)(ac+asum) / double(bc+bsum) > (double)(a+asum) / (double)(b+bsum);
}


void clearUnion() {
  parent.resize(N);
  parent_rank.resize(N);
  for (int i = 0; i < N; i++) parent[i] = i, parent_rank[i]=1;
}

int main() {
cin >> N >> M;

  parent.resize(N);
  parent_rank.resize(N);
  for (int i = 0; i < N; i++) parent[i] = i, parent_rank[i]=1;

  vector<Edge> edges;
  

  REP(i, M) {
    Edge e;
    cin >> e.u >> e.v >> e.a >> e.b;
    if (e.u == e.v ) {
      continue;
    }
    if (G[e.u][e.v].count(e.a)) {
      //cout << e.a << " / " << G[e.u][e.v][e.a] << " vs " << e.a << " / " << e.b <<  " = " << min(G[e.u][e.v][e.a], e.b) << endl;
      G[e.u][e.v][e.a] = min(G[e.u][e.v][e.a], e.b);
      G[e.v][e.u][e.a] = min(G[e.v][e.u][e.a], e.b);
    } else {
      G[e.u][e.v][e.a] = e.b;
      G[e.v][e.u][e.a] = e.b;
    }
  }

  find_bridges();
  int a_start = 0;
  int b_start = 0;
  for (auto p: bridges){
    int u = p.first;
    int v = p.second;
    int a = G[u][v].begin()->first;
    int b = G[u][v].begin()->second;
    a_start += a;
    b_start += b;
    G[u].erase(v);
    G[v].erase(u);
  }

  auto parent_start = parent;
  auto parent_rank_start = parent_rank;

  unordered_map<int, vector<pii>> pos;

  for (int i = 0; i < N; i++) {
    for (auto &j : G[i]) {
      if (i > j.first) continue;

      unordered_map<int,int> m2;

      for (auto &k : j.second) {
        int a = k.first;
        int b = k.second;
        if (m2.count(b)) {
          //cout << m2[b] << " / " << b  << " vs " << a << " / " << b <<  " = " << max(m2[b], a) << endl;
          m2[b] = max(m2[b], a);
        } else {
          m2[b] = a;
        }
      }

      j.second = m2;
      G[j.first][i] = m2;

      for (auto &k : j.second) {
        Edge e;
        e.b = k.first;
        e.a = k.second;
        e.u = i;
        e.v = j.first;
        //cout << "pushing " << e.a << " " << e.b << " " << " " << e.u << " " << e.v << " " << endl;
        edges.pb(e);
      }
    }
  }

  int aans = a_start;
  int bans = b_start;
  int t= 0;

  while (true) {

    int asum = a_start;
    int bsum = b_start;
    int chosen = 0;

    clearUnion();
    vector<unordered_map<int,pii>> mst(N);

    for (auto e : edges) {
      if (find_parent(e.u)==find_parent(e.v)) continue;
      merge_nodes(e.u, e.v);
      asum += e.a;
      bsum += e.b;
      chosen++;
      if (chosen + bridges.size() == N-1) break;
    }

    sort(edges.begin(), edges.end(), [&](Edge &a, Edge &b) {
      return ((double)(a.a + asum) / (double)(a.b + bsum) > (double)(b.a + asum) / (double)(b.b + bsum));
    });

    if (aans == asum && bans == bsum) break;
    aans = asum;
    bans = bsum;

  }



  int d = gcd(aans, bans);
  aans /= d;
  bans /= d;

  printf("%d/%d\n", aans, bans);

  return 0;
}

