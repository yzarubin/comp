//#include<bits/stdc++.h>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <sstream>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <unordered_map>
#include <limits.h>
#include <bitset>
#include <unordered_set>
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

void normalizestr(string &s) {
  int ch[26] = {0};
  for (auto &c : s) ch[c-'a']++;
  int mp[26] = {0};

  int i = 0;
  for (int j = 0; j < 26; j++) {
    if (ch[j] > 0) {
      mp[j] = i;
      i++;
    }
  }

  for (auto &c : s) c = mp[c-'a']+'a';
}

string splits(string &s, int p) {
  if (p == 0) return s.substr(0);
  else return s.substr(p) + s.substr(0, p);
}

unordered_map<string, ll> memo;

int go(string s, int i) {
  if (s.empty()) return 0;

  auto it = memo.find(s);
  if (it != memo.end()) return it->second;
  
  int j = 0;
  int ans = 0;

  while (s[j] - 'a' == i) j++;
  if (j == s.size()) return 0;

  vector<int> pos;
  string tmp;

  while (j < s.size()) {
    if (s[j] - 'a' == i) {
      ans++;
      while (j < s.size() && s[j] - 'a' == i) j++;

      if (j == s.size()) pos.push_back(0);
      else pos.push_back(tmp.size());
     
    } else {
      tmp.push_back(s[j]);
      j++;
    }
  }

  if (pos.empty()) {
    ans += go(tmp, i+1);
  } else {
    int next_ans = INT_MAX;
    for (auto p : pos) {
      next_ans = min(next_ans, go(splits(tmp, p), i+1));
    }

    ans += next_ans;
  }
  
  memo[s] = ans;
  return ans;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;

  while (q--) {
    string s; cin >> s;
    normalizestr(s);
    auto ans = go(s, 0);
    cout << ans << endl;
  }
  

  return 0;
}
