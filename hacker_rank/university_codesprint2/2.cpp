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


bool go(ll num, string s) {
  if (s.empty()) return true;
  if (s[0] == '0') return false;
  
  ll g = 0;

  for (ll i = 0; i < s.size(); i++) {
    g = g * 10 + s[i] - '0';
    if (g > num + 1) return false;
    if (g == num + 1) return go(num + 1, s.substr(i + 1));
  }

  return false;

}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int q; cin >> q;

  while (q--) {
    string s; cin >> s;

    if (s[0] == '0') {
      printf("NO\n");
    } else {
      ll k = 0;
      bool ok = false;
      for (ll i = 0; i < s.size() - 1; i++) {
        k = k * 10 + s[i]-'0';

        ok = go(k, s.substr(i + 1));
        if (ok) break;
      }
      if (ok) printf("YES %lld\n", k);
      else printf("NO\n");

    }
  }
  
  return 0;
}
