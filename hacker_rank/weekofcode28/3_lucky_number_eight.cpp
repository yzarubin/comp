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


ll fast_mod_exp(ll a, ll b, ll p) {
  ll res = 1;

  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a= (a * a) % p;
    b >>= 1;
  }
 
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  ll ans = 0;

  vector<string> mult2;
  vector<string> mult3;

  // wtf??
  mult2.push_back("00");
  mult2.push_back("08");
  mult3.push_back("000");
  mult3.push_back("008");

  for (int i = 9; i < 1000; i++) {
    if (i % 8 == 0) {
      if (i < 100) {
        mult2.push_back(to_string(i));
        mult3.push_back("0" + to_string(i));
      }
      else mult3.push_back(to_string(i));
    }
  }

  vector<vector<ll>> single(10, vector<ll>(n+1));
  for (int i = 0; i <= 9; i++) {
    for (int j = n - 1; j >= 0; j--) {
      single[i][j] = single[i][j + 1] + (s[j] == i + '0');
    }
  }


  REP(i, n) if (s[i] == '8' || s[i] == '0') addmod(ans, 1);

  for (auto d : mult2) {
    for (int i = 0; i < n; i++) {
      if (s[i] == d[0]) {
        addmod(ans, single[d[1] - '0'][i+1]);
      }
    }
  }

  for (auto d: mult3) {
    vector<ll> memo(n+1);

    for (int j = n - 1; j >= 0; j--) {
      memo[j] = memo[j+1];
      if (s[j] == d[1]) addmod(memo[j], single[ d[2] - '0' ][j+1]);
    }

    for (int i = 0; i < n; i++) {
      if (s[i] == d[0] && memo[i+1]) {
        ll f = fast_mod_exp(2, i, bs);
        ll g = f * (memo[i+1] % bs) % bs;

        addmod(ans, g);
      }
    }
  }

  cout << ans % bs << endl;

  return 0;
}




