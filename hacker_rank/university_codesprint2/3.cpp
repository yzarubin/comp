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


/*************SOLUTION*************/


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int g; cin >> g;

  while (g--) {
    ll n, m, x; cin >> n >> m >> x;

    vector<ll> a1(n);
    vector<ll> a2(m);
    REP(i, n) cin >> a1[i];
    REP(i, m) cin >> a2[i];

    ll s = 0;
    int i = -1;
    while (i + 1 < n && s + a1[i + 1] <= x) s += a1[i++];

    int j = 0;

    while (j < m && s + a2[j] <= x) s += a2[j++];

    int ans = i + 1 + j;
    while (i >= 0) {
      s -= a1[i--];
      while (j < m && s + a2[j] <= x) s += a2[j++];
      ans = max(ans, i + 1 + j);
    }

    cout << ans << endl;
  }
 
  
  return 0;
}
