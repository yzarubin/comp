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
#define REPI(i,a,n) for (int i=a; i < (int)(n); ++i)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define PI 3.14159265

void addmod(ll &a, ll b){a = (a + b); if (a >= bs) a -= bs;}
void mulmod(ll &a, ll b){a = (a * b) % bs;}
template<class T>inline void cmax(T &x, const T &y) {if (x < y) x = y;}
template<class T>inline void cmin(T &x, const T &y) {if (y < x) x = y;}
struct cmp { bool operator()(int &a, int &b) { return a < b; }};

//cout << fixed << setprecision(16);

template<typename T>
string sv(vector<T> &v) {
  if (v.size() == 0) return "[]";
  stringstream ss;
  ss << "[";
  for (std::size_t i = 0; i < v.size() - 1; ++i) ss << v[i] << ", ";
  ss << v[v.size() - 1] << "]";
  return ss.str();
}


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int ts; cin >> ts;

  REPI(t, 1, ts+1) {

    int n, q; cin >> n >> q;

    vector<ll> nums(n);
    REP(i, n) cin >> nums[i];

    vector<ll> pre(n+1);

    for (int i = 0; i < SZ(nums); i++) {
      pre[i+1] = pre[i] + nums[i];
    }

    vector<ll> sums(n*102);

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        ll k = pre[j+1] - pre[i];
        sums[k]++;
      }
    }
    cout  << "Case #" << t << ": " << endl;

    while (q--) {
      ll l, r; cin >> l >> r;
      l--; r--;

      ll p = 0;
      ll i = 0;

      while (p + sums[i] < l) {
        p += sums[i];
        i++;
      }

      ll tmp = i;
      ll need = r-l+1;
      sums[tmp] -= l - p;
      ll ans = 0;

      while (need) {
        ans += i * min(sums[i], need);
        need -= min(sums[i], need);
        i++;
      }

      sums[tmp] += l - p;

      cout << ans << endl;

    }
  }
  
  return 0;
}




