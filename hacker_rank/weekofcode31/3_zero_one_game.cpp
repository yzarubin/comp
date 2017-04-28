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
  int g; cin >> g;

  while (g--) {
    int n; cin >> n;
    vector<int> v(n);
    REP(i, n) cin >> v[i];

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      if (v[i] == 1 && v[i-1] == 0 && v[i+1] == 0) v[i] = 2, ans++;
    }
    
    for (int i = 1; i < n - 1; i++) {
      if (v[i] == 0 && (v[i-1] == 0 || v[i-1] == 2) && (v[i+1] == 0 || v[i+1] == 2)) ans++;
    }

    cout << (ans % 2 == 1 ? "Alice" : "Bob") << endl;
  }
  return 0;
}

