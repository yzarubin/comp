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

static const long long bs = 998244353;
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

int n, m, k;

vector<int> ans(6*1e4+5);

vector<vector<int>> movememo(6 * 1e4 + 5);
vector<int> jmp;
vector<int> prob;

int moveto(int from, int moves) {
  if (!moves) return from;
  if (movememo[from][moves] != -1) return movememo[from][moves];

  int next = jmp[from];
  if (next == from) return from;
  int ans = moveto(next, moves - 1);

  movememo[from][moves] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  jmp.resize(n+1);
  prob.resize(m+5);
  REP(i, n) cin >> jmp[i+1];
  REP(i, m) cin >> prob[i];
  REP(i, n) movememo[i+1].resize(m+5, -1);

  ll start = mod_inverse(n, bs);
  vector<ll> ans(n+1);
  vector<ll> state1(n+1, start);
  vector<ll> state2(n+1);

  REP(q, k) {
    for (int i = 0; i < m; i++) {
      for (int j = 1; j <= n; j++) {
        ll p = prob[i];
        int next_idx = moveto(j, i);
        //cout << "turn " << q+1 << " roll " << i << " position " << j <<  " || nextpos " << next_idx << endl; 
        ll chance = state1[j] * p % bs;

        addmod(state2[next_idx], chance);
      }
    }
    cout << sv(state2) << endl;

    for (int j = 1; j <= n; j++) {
      state1[j] = state2[j];
      state2[j] = 0;
    }
  }

  for (int j = 1; j <= n; j++) printf("%lld\n", state1[j]);

  //cout << mod_inverse(3, bs) * mod_inverse(4, bs) % bs;

  return 0;
}
