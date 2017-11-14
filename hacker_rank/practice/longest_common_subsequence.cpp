#include <bits/stdc++.h>

using namespace std;

int a1[105], a2[105], dp[105][105];

int main() {

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a1[i];
	for (int i = 0; i < m; i++) cin >> a2[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a1[i] == a2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	vector<int> ans;

	for (int x = n - 1, y = m - 1; x >= 0; x--) {
		for (int tmp = y; tmp >= 0; tmp--) {
			if (dp[x][tmp] + 1 == dp[x + 1][tmp + 1] && a1[x] == a2[tmp]) {
				ans.push_back(a1[x]);
				y = tmp;
				break;
			} else if (dp[x][tmp] == dp[x + 1][tmp]) {
				break;
			}
		}
	}

	for (int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';

	return 0;
}
