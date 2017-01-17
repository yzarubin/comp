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

int K = 0;
int N = 0;

#define ALLOCATE_TO 2600000
#define ALLOCATE_BUCKET 23

double arrm[ALLOCATE_BUCKET][ALLOCATE_TO];
vector<map<int, double>> memo(32);

int maskright[32] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647};
int maskleft[32] = {2147483646, 2147483644, -8, -16, -32, -64, -128, -256, -512, -1024, -2048, -4096, -8192, -16384, -32768, -65536, -131072, -262144, -524288, -1048576, -2097152, -4194304, -8388608, -16777216, -33554432, -67108864, -134217728, -268435456, -536870912, -1073741824, -2147483648, 0};
int allocm[32] = {0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32767,65399,127858,230964,354522,431910,401930,280600,145499,55455,15276,2952,379,29,1,0};

int splitn(int g, int i) {
  return ((maskleft[i] & g) >> 1) | (maskright[i] & g);
}

void set_memo(int g, int n, double res) {
  if (g >= ALLOCATE_TO || n >= ALLOCATE_BUCKET) {
    memo[n][g] = res;
  } else {
    arrm[n][g] = res;
  }
}

double get_memo(int g, int n) {
  if (g >= ALLOCATE_TO || n >= ALLOCATE_BUCKET) {
    auto it = memo[n].find(g);
    return it == memo[n].end() ? -1.0 : it->second;
  } else {
    return arrm[n][g];
  }
}


double go(int g, int n) {
  int a = N - n;
  if (a == K) return 0;

  auto p = get_memo(g, n);

  if (p != -1.0) return p;

  double res = 0.0;
  double nd = n;

  for (int i = 0; i < n; i++) {
    int first = (1 << i);
    int last = (1 << (n - i - 1));

    double remfirst = go(splitn(g, i), n-1);
    double remlast = go(splitn(g, n-i-1), n-1);

    if ((g & first) == first) remfirst += 1.0;
    if ((g & last) == last) remlast += 1.0;
    res += max(remfirst, remlast) / nd;
  }

  set_memo(g, n, res);

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  string s; cin >> s;
 
  int g = 0;
  REP(i, N) if (s[N-1-i] == 'W') g |= (1 << i);

  fill(*arrm, *arrm + ALLOCATE_TO * ALLOCATE_BUCKET, -1.0);

  double ans = go(g, N);
  printf("%lf\n", ans);

  return 0;
}




