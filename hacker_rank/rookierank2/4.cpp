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
#define pb push_back
#define mp make_pair
#define PI 3.14159265

void addmod(ll &a, ll b){a = (a + b); if (a >= bs) a -= bs;}
void mulmod(ll &a, ll b){a = (a * b) % bs;}
template<class T>inline void cmax(T &x, const T &y) {if (x < y) x = y;}
template<class T>inline void cmin(T &x, const T &y) {if (y < x) x = y;}
struct cmp { bool operator()(int &a, int &b) { return a < b; }};

// KnightL on a Chessboard

int go(int a, int b, int n) {

  queue<pair<int, pii>> q;
  q.push({0,{0,0}});

  int mx[8] = {a, a, -a, -a, b, -b, b, -b};
  int my[8] = {b, -b, b, -b, a, a, -a, -a};

  map<pii, bool> m;

  while (q.size()) {
    auto next = q.front(); q.pop();
    auto pos = next.second;

    int i = pos.first;
    int j = pos.second;
    if (m[pos]) continue;
    m[pos] = true;

    if (i == n-1 && j == n-1) return next.first;

    REP(k, 8) {
      int ii = mx[k] + i;
      int jj = my[k] + j;
      if (ii < 0 || jj < 0 || ii >= n || j >= n) continue;
      q.push({next.first + 1, {ii, jj}});
    }
  }

  return -1;

}




int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n; cin >> n;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      cout << go(i, j, n) << " ";
    }
    cout << endl;
  }
  
  
  return 0;
}


 

