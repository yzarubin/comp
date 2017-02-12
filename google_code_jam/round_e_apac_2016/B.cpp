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
#define pb push_back
#define mp make_pair
#define PI 3.14159265
void addmod(ll &a, ll b){a = (a + b); if (a >= bs) a -= bs;}
void mulmod(ll &a, ll b){a = (a * b) % bs;}

template<class T>inline void cmax(T &x, const T &y) {if (x < y) x = y;}
template<class T>inline void cmin(T &x, const T &y) {if (y < x) x = y;}
struct cmp { bool operator()(int &a, int &b) { return a < b; }};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
      
    ll n, k; cin >> n >> k;
    vector<ll> r1(n);
    vector<ll> r2(n);

    REP(i, n) cin >> r1[i];
    REP(i, n) cin >> r2[i];

    unordered_map<ll,ll> m1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ll p = r1[i] ^ r2[j];
        m1[p]++;
      }
    }

    REP(i, n) cin >> r1[i];
    REP(i, n) cin >> r2[i];

    unordered_map<ll,ll> m2;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ll p = r1[i] ^ r2[j];
        m2[p]++;
      }
    }

    ll ans = 0;

    for (auto i : m1) {

      ll g = k ^ i.first;

      ans += m2[g] * i.second;
      
    }

    cout << "Case #" << t << ": " << ans << endl;

  }

  
  return 0;
}




