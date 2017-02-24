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
  
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  ll k1 = 0, k2 = 0;
  k1 = k2 = a[0];
  ll ans1 = 0, ans2 = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > k1) {
      ans1++;
      k1 = a[i];
    } else if (a[i] < k2) {
      ans2++;
      k2 = a[i];
    }
  }

  cout << ans1 << " " << ans2;
  
  return 0;
}
