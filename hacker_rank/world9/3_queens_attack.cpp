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

unordered_map<int, unordered_map<int, bool>> m;


int mx[8] = {1,1,-1,-1,0,0,1,-1};
int my[8] = {1,-1,1,-1,1,-1,0,0};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int rq, cq; cin >> rq >> cq;

  while (k--) {
    int r, c; cin >> r >> c;
    m[r][c] = true;
  }
  int ans = 0;

  for (int i = 0; i < 8; i++) {
    int r = rq;
    int c = cq;

    while (true) {
      r += mx[i];
      c += my[i];
      if (r < 1 || r > n || c < 1 || c > n) break;

      if (m.count(r) && m[r].count(c)) break;
      ans++;
    }
  }
  cout << ans << endl;
  
  return 0;
}




