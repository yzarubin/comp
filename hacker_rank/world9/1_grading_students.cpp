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


  int n; cin >> n;
  while (n--) {
    int k; cin >> k;
    if (k < 38) cout << k << endl;
    else {
      if ((k + 1) % 5 == 0) {
        cout << k + 1 << endl;
      } else if ((k + 2) % 5 == 0) {
        cout << k + 2 << endl;
      } else {
        cout << k << endl;
      }
    }
  }
  
  return 0;
}




