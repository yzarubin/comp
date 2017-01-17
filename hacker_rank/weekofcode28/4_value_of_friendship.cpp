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

template<class T>bool cmpmin(T &a, T &b){return a>b?a=b,1:0;}
template<class T>bool cmpmax(T &a, T &b){return a<b?a=b,1:0;}

struct cmp {
  bool operator()(int &a, int &b) { return a < b; }
};

template<typename T>
string sv(vector<T> &v) {
  if (v.size() == 0) return "[]";
  stringstream ss;
  ss << "[";
  for (std::size_t i = 0; i < v.size() - 1; ++i) ss << v[i] << ", ";
  ss << v[v.size() - 1] << "]";
  return ss.str();
}

template<typename T>
void sv2d(vector<vector<T>> &v) {
  for (int i = 0; i < v.size(); i++) cout << sv(v[i]) << endl;
}

// Disjoint set

vector<ll> parent;
vector<ll> parent_rank;

int find_parent(int n) {
  if (parent[n] != n) parent[n] = find_parent(parent[n]);
  return parent[n];
}

void merge(int a, int b) {
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


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;

  while (q--) {
    int n; cin >> n;
    int m; cin >> m;

    parent.clear();
    parent.resize(n+1);
    parent_rank.clear();
    parent_rank.resize(n+1, 1);

    for (int i = 1; i <= n; i++) parent[i] = i;

    vector<vector<int>> G(n+1);
    
    REP(i, m) {
      int a, b; cin >> a >> b;
      G[a].pb(b);
      G[b].pb(a);
    }

    queue<int> q;
    vector<int> visited(n+1);

    ll pcount = 0;

    for (int i = 1; i <= n; i++) {
      if (visited[i]) continue;
      q.push(i);

      while (q.size()) {
        int a = q.front(); q.pop();
        if (visited[a]) continue;
        visited[a] = true;

        int aa = find_parent(a);
        
        for (auto b : G[a]) {
          if (visited[b]) continue;

          int bb = find_parent(b);
          if (aa == bb) { 
            pcount++;
          } else {
            merge(aa, bb);
            q.push(b);
          }
        }
      }
    }

    unordered_set<int> ps;
    for (int i = 1; i <= n; i++) ps.insert(find_parent(i));
  
    vector<ll> ranks;
    for (auto s : ps) ranks.push_back(parent_rank[s]);
    sort(ranks.begin(), ranks.end(), greater<ll>());

    ll ans = 0;
    ll inc = 0;

    for (auto r : ranks) {
      for (int i = 2; i <= r; i++) {
        inc += (i - 1) * 2;
        ans += inc;
      }
    }

    ans += pcount * inc;
    cout << ans << endl;

  }
  
  return 0;
}




