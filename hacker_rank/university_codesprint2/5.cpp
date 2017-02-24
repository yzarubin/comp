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

vector<vector<ll>> pt;
void pascal(ll n) {
  for (ll line = 0; line < n; line++) {
    pt.push_back(vector<ll>(line + 1));
    for (ll i = 0; i <= line; i++) {
      if (line == i || i == 0) pt[line][i] = 1;
      else pt[line][i] = (pt[line-1][i-1] + pt[line-1][i]) % bs;
    }
  }
}

int nchunk = 0;
vector<pair<int, ll>> dp(1205);
vector<ll> ps(1205);
vector<vector<pair<int, ll>>> memo(1205, vector<pair<int, ll>>(1205, mp(-1,-1)));

ll go(ll i, ll rem, int chunk) {
  if (i <= 1) return 1;
  if (memo[i][rem].first == chunk) return memo[i][rem].second;
  ll ans = 0;

  if (rem == 0) {
    if (chunk == nchunk-1) return 1;
    for (int j = 1; j <= i; j++) {
      if (dp[j].first != chunk+1) break;
      ll c = pt[i][j] * ps[j] % bs * dp[j].second % bs;

      ans = (ans + c) % bs;
    }
  } else {
    for (ll j = min(rem, i); j >= 1; j--) {
      ll res = go(j, rem - j, chunk);
      ll c = pt[i][j] * ps[j] % bs * res % bs;

      ans = (ans + c) % bs;
    }
  }

  memo[i][rem] = {chunk, ans};
  return ans;
}


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n; cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  ps[0] = 1;
  ps[1] = 1;

  for (ll i = 1; i < 1205; i++) {
    ps[i] = i * ps[i-1] % bs;
  }

  pascal(1205);

  int start = 0;
  vector<ll> chunks;
  for (int i = 1; i <= n; i++) {
    if (i == n || a[i] < a[i-1]) {
      chunks.pb(i-start);
      start = i;
    }
  }

  for (int i = 0; i < dp.size(); i++) dp[i] = {chunks.size(), 1};

  nchunk = chunks.size();

  for (int i = chunks.size() - 1; i >= 0; i--) {
    vector<ll> dp2(chunks[i] + 1);
    for (int j = 1; j <= chunks[i]; j++) {
      ll ans = go(j, chunks[i] - j, i) % bs;
      dp2[j] = ans;
    }

    for (int k = 1; k < dp2.size(); k++) {
      dp[k] = {i, dp2[k]};
    }

  }

  ll ans = 0;
  for (auto &i : dp) {
    if (i.first == 0) ans = (ans + i.second) % bs;
  }

  cout << ans % bs << endl;
  
  return 0;
}
