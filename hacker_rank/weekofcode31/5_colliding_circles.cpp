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
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1)

void addmod(ll &a, ll b){a = (a + b); if (a >= bs) a -= bs;}
void mulmod(ll &a, ll b){a = (a * b) % bs;}
template<class T>inline void cmax(T &x, const T &y) {if (x < y) x = y;}
template<class T>inline void cmin(T &x, const T &y) {if (y < x) x = y;}
struct cmp { bool operator()(int &a, int &b) { return a < b; }};

double radius(double i) {
  return i * i * PI;
}

/*************SOLUTION*************/

int main() {
  int n, k; cin >> n >> k;

  double start = 0;
  double end = 0;

  REP(i, n) {
    int q; cin >> q;
    start += radius(q), end += q;
  }
  end = radius(end);

  double diff = end - start;
  double m = 1.0;

  for (int i = 3; i <= n; i++) {
    m *= (double)(i - 2) / double(i - 2 + 2);
  }

  double ans = start;

  for (int i = 1; i <= k; i++) {
    ans += diff * m;
    m *= 1.0 + 2.0 / ((double)n - (double)i);
  }

  cout << setprecision(15) <<  ans << endl;
  return 0;
}