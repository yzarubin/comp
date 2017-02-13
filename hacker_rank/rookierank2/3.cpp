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
#define pb push_back
#define mp make_pair
#define PI 3.14159265

void addmod(ll &a, ll b){a = (a + b); if (a >= bs) a -= bs;}
void mulmod(ll &a, ll b){a = (a * b) % bs;}
template<class T>inline void cmax(T &x, const T &y) {if (x < y) x = y;}
template<class T>inline void cmin(T &x, const T &y) {if (y < x) x = y;}
struct cmp { bool operator()(int &a, int &b) { return a < b; }};


// HackerRank in a String!

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int q; cin >> q;
  string t = "hackerrank";
  while (q--) {
    string s; cin >> s;

    int j = 0;

    for (int i = 0; i < s.size() && j < t.size(); i++) {
      if (s[i] == t[j]) {
        j++;
      }
    }

    cout << (j==t.size()?"YES":"NO") <<endl;


  }

  
  
  return 0;
}




