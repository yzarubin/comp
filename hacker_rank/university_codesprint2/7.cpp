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

template<typename T>
string sv(vector<T> &v) {
  if (v.size() == 0) return "[]";
  stringstream ss;
  ss << "[";
  for (std::size_t i = 0; i < v.size() - 1; ++i) ss << v[i] << ", ";
  ss << v[v.size() - 1] << "]";
  return ss.str();
}

template<typename T>
void sv2d(vector<vector<T>> &v) {
  for (int i = 0; i < v.size(); i++) cout << sv(v[i]) << endl;
}


ll ans1(ll n, ll m, ll s) {
  ll e_cnt_free = (n-1) * (n-2) / 2;
  ll sink = s - (n-2);
  ll non_free = m - e_cnt_free;
  return e_cnt_free + non_free * sink;
}

ll ans2(ll n, ll m, ll s) {

  ll lower = s / (n-1);
  ll rem = s % (n-1);

  ll e_cnt_free = (n-1) * (n-2) / 2;
  ll non_free = m - e_cnt_free;

  ll spath = (n-2) * lower;

  return e_cnt_free * lower + non_free * (s - spath);
}

ll ans3(ll n, ll m, ll s) {
  ll lower = s / (n - 1);
  ll rem = s % (n - 1);

  if (!rem) return LONG_MAX;
  
  ll e_cnt_free = (n-1) * (n-2) / 2;
  ll non_free = m - e_cnt_free;

  ll e = n - 1;
  ll fe = e - rem;


  ll p1 = ((fe * (fe+1)) / 2);
  ll extra = (e - non_free) * (lower + 1);
  ll p2 = (lower+1) * (e * (e+1) / 2) - p1 - extra;

  return p2;
}

ll calc(ll n, ll m, ll s) {
  ll e_cnt_free = (n-1) * (n-2) / 2;

  if (m <= e_cnt_free + 1) {
    return m + s - (n - 1);
  }

  ll a1 = ans1(n,m,s);
  ll a2 = ans2(n,m,s);
  ll a3 = ans3(n,m,s);

  return min(a1,min(a2,a3));
}


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int q; cin >> q;
  while (q--) {
    ll n, m, s; cin >> n >> m >> s;
    cout << calc(n, m, s) << endl;
  }

  return 0;
}
