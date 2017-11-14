#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// https://www.hackerrank.com/challenges/find-maximum-index-product

int main() {
	int N; cin >> N;

	vector<pair<ll, ll>> st;
	ll ans = 0;

	for (int i = 1; i <= N; i++) {
		int k; cin >> k;

		if (st.empty() || k <= st.back().first) {
			st.push_back({k, i});
		} else {
			while (st.size() && st.back().first < k) {
				auto b = st.back(); st.pop_back();
				if (st.size() && st.back().first != b.first) {
					ans = max(ans, st.back().second * i);
				}
			}

			st.push_back({k, i});
		}
	}

	cout << ans << endl;

	return 0;
}
