#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct fenwick {
    vector<long long> tree;
    vector<long long> tree2;

    fenwick(int n = 0) {
        init(n);
    }

    // init for range [0, n]
    void init(int n) {
        tree.assign(n + 2, 0);
        tree2.assign(n + 2, 0);
    }

    // [i] + val
    void add(int i, long long val) {
        add_range(i, i, val);
    }

    // [l, r] + val
    void add_range(int l, int r, long long val)  { 
        l++, r++;
        for (int tl = l; tl < tree.size(); tl += (tl & -tl)) {
            tree[tl] += val, tree2[tl] -= val * (long long)(l - 1);
        }

        for (int tr = r + 1; tr < tree.size(); tr += (tr & -tr)) {
            tree[tr] -= val, tree2[tr] += val * (long long)(r);
        }
    }

    //[0, r]
    long long sum(int r)  {   
        r++;                      
        long long res = 0;
        for (int tr = r; tr; tr -= (tr & -tr)) {
            res += tree[tr] * (long long)(r) + tree2[tr];
        }
        return res;
    }

    long long range(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

// https://www.hackerrank.com/challenges/candles-2

int main() {
	ll N, K; cin >> N >> K;
	ll MOD = 1e9 + 7;
	ll G = 5 * 1e4 + 1;

	vector<fenwick> fwt(1 << K, fenwick(G));

	for (ll i = 0; i < N; i++) {
		ll h, c; cin >> h >> c;
		c--;

		ll g = 1 << c;

		for (int j = 1; j <= (1 << K) - 1; j++) {
			if ((j & g) == g) {
				ll c1 = fwt[j ^ g].sum(h - 1) % MOD;
				ll c2 = fwt[j].sum(h - 1) % MOD;
				ll b = (j == g);
				fwt[j].add(h, c1 + c2 + b);
			}
		}
	}

	cout << fwt[(1 << K) - 1].sum(G) % MOD << endl;

	return 0;
}

