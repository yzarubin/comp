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
struct cmp { bool operator()(int &a, int &b) { return a < b; }};


/*************SOLUTION*************/

ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) a %= b;
    else b %= a;
  }

  return a + b;
}


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int q; cin >> q;

  while (q--) {

    int N; cin >> N;

    vector<vector<int>> G(N+1);

    REP(i, N-1) {
      int u, v; cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
    }

    unordered_map<int, unordered_map<int, bool>> guess;
    unordered_map<int, unordered_map<int, ll>> memo;


    function<ll(int, int)> dfs = [&](int node, int parent) {
      if (memo.count(parent) && memo[parent].count(node)) return memo[parent][node];

      ll ans = guess[parent][node];

      for (auto k : G[node]) {
        if (k == parent) continue;
        ans += dfs(k, node);
      }

      return memo[parent][node] = ans;
    };


    int g, k; cin >> g >> k;

    REP(i, g) {
      int parent, node; cin >> parent >> node;
      guess[parent][node] = true;
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
      ll c = dfs(i, -1);
      if (c >= k) ans++;
    }

    cout << ans / gcd(ans, N) << "/" << N / gcd(ans, N)  << endl;
  }
  
  return 0;
}
