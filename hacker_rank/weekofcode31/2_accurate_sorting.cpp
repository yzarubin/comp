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


string solve(vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != i && abs(nums[i] - nums[i + 1]) == 1) swap(nums[i], nums[i + 1]);
    if (nums[i] != i) return "No";
  }
  return "Yes";
    
}

int main() {
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    cout << solve(nums) << endl;
  }
  return 0;
}