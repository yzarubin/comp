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

// Migratory Birds

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  int a[10];
  REP(i, n) {
    int k; cin >> k;
    a[k]++;
  }

  int ans = 0;
  for (int i = 0; i < 10; i++) {
    if (a[i] > a[ans]) ans = i;
  }
  cout << i << endl;

  
  return 0;
}




