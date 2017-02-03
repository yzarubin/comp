//#include<bits/stdc++.h>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <sstream>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <unordered_map>
#include <limits.h>
#include <bitset>
#include <unordered_set>
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
#define pb push_back
#define mp make_pair
#define PI 3.14159265
void addmod(ll &a, ll b){a = (a + b); if (a >= bs) a -= bs;}
void mulmod(ll &a, ll b){a = (a * b) % bs;}

struct cmp {
  bool operator()(int &a, int &b) { return a < b; }
};


ll fast_mod_exp(ll a, ll b, ll p) {
  ll res = 1;

  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a= (a * a) % p;
    b >>= 1;
  }
 
  return res;
}

ll mod_inverse(ll a, ll p) {
  return fast_mod_exp(a, p-2, p);
}

vector<vector<int>> G(2*1e5+5);

vector<vector<vector<ll>>> memo(2, vector<vector<ll>>(2,  vector<ll>(2*1e5+5, -1)));

ll dfs(int n, int parentN, int player, int parentPlayer) {
  if (memo[player][parentPlayer][n] != -1) return memo[player][parentPlayer][n];

  if (G[n].size() == 1) {
    if (G[n][0] == parentN) {
      if (G[n].size() == 1 && player != parentPlayer) return 0;
      if (G[n].size() == 1 && player == parentPlayer) return 1;
    }
  }

  ll otherProduct = 1;
  ll ans = 1;

  for (auto child : G[n]) {
    if (child == parentN) continue;

    ll same = dfs(child, n, player, player);
    ll other = dfs(child, n, player ^ 1, player);

    ans = ans * ((same + other) % bs) % bs;
    otherProduct = otherProduct * other % bs;
  }

  if (otherProduct > 0 && parentPlayer != player) {
    ans = ans + bs - otherProduct;
  }


  assert(ans >= 0);

  memo[player][parentPlayer][n] = ans % bs;
  return memo[player][parentPlayer][n];
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  REP(i, n-1) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  ll a1 = dfs(1, -1, 0, 1) % bs;
  ll a2 = dfs(1, -1, 1, 0) % bs;

  cout << (a1 + a2) % bs << endl;

  return 0;
}




