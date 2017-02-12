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


ll N, X, K, A, B, C;
vector<unordered_map<ll,double>> memo(100005);


double go(ll n, ll s) {
  if (n == 0) return (double)s;
  auto it = memo[n].find(s);
  if (it != memo[n].end()) return it->second;


  double a = go(n-1, s & K) * A/100.0;
  double b = go(n-1, s | K) * B/100.0; 
  double c = go(n-1, s ^ K) * C/100.0;

  memo[n][s] = a+b+c;
  return a+b+c;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    
    cin >> N>>X>>K>>A>>B>>C;
    REP(i, 100005) memo[i].clear();

    cout  << "Case #" << t << ": " << go(N, X) << endl;

  }

  
  return 0;
}




