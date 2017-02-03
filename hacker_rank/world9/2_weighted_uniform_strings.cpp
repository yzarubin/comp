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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;

  unordered_set<int> st;

  int g = s[0] - 'a' + 1;
  st.insert(g);
  for (int i = 1; i < s.size(); i++) {
    if (s[i-1] == s[i]) g += s[i] - 'a' + 1;
    else g = s[i] -'a' + 1;
    st.insert(g);
  }

  int q; cin >> q;
  while (q--) {
    int k; cin >> k;
    cout << (st.count(k) ? "Yes" : "No") << endl; 

  }
  
  return 0;
}




