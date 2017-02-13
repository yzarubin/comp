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


// Prefix Neighbors

struct Trie {
  ll v = 0;
  Trie* a[26] = {NULL};
};

unordered_map<Trie*, ll> memo[2];

ll go(Trie* root, bool skip) {
  if (!root) return 0;

  auto it = memo[skip].find(root);
  if (it != memo[skip].end()) return it->second;

  ll ans = 0;

  if (root->v > 0) {
    if (skip) REP(i, 26) ans += go(root->a[i], !skip);
    else {
      ll sum1 = root->v;
      ll sum2 = 0;

      REP(i, 26) sum1 += go(root->a[i], true);
      REP(i, 26) sum2 += go(root->a[i], false);

      ans = max(sum1, sum2);
    }

  } else {
    REP(i, 26) ans += go(root->a[i], skip);
  }

  memo[skip][root] = ans;
  return ans;

}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n; cin >> n;
  auto root = new Trie;

  REP(i, n) {
    string s; cin >> s;

    auto cur = root;
    ll sum = 0;

    for (auto c : s) {
      sum += c;
      int ch = c-'A';
      if (!cur->a[ch]) cur->a[ch] = new Trie;
      cur = cur->a[ch];
    }

    cur->v = sum;
  }

  cout << go(root, false) << endl;
  
  return 0;
}


 

