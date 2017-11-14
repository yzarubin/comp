#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ss(ll n) {
    return n * (n + 1LL) / 2LL;
}

// https://www.hackerrank.com/challenges/jim-and-the-skyscrapers

int main() {
    int N; cin >> N;

    vector<pair<int, int>> g;

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        ll k; cin >> k;

        while (g.size() && k > g.back().first) {
            ans += ss(g.back().second - 1);
            g.pop_back();
        }

        if (g.size() && k == g.back().first) {
            g[g.size() - 1].second++;
        } else {
            g.push_back({k, 1});
        }
    }

    while (g.size()) {
        ans += ss(g.back().second - 1);
        g.pop_back();
    }

    cout << ans * 2LL << endl;

    return 0;
}

