#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct fenwick {
    vector<long long> tree;
    fenwick(int n = 0) {
        init(n);
    }

    // init for range [0, n]
    void init(int n) {
        tree.assign(n + 2, 0);
    }

    // [i] + val
    void add(int i, long long val) {
        i++;
        while (i < tree.size()) {
            tree[i] += val;
            i += i & -i;
        }
    }

    // sum [0, r]
    long long query(int r) {
        r++;
        long long sum = 0;
        while (r > 0){
            sum += tree[r];
            r -= (r & -r);
        }
        return sum;
    }

    // sum [l, r]
    long long sum_range(int l, int r) {
        return query(r) - query(l - 1);
    }
};

struct union_find {
    vector<int> parent;
    vector<int> rank;

    int find(int a) {
      if (parent[a] != a) parent[a] = find(parent[a]);
      return parent[a];
    }

    void init(int n) {
        parent.resize(n);
        rank.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    void merge(int a, int b) {
        int aa = find(a);
        int bb = find(b);

        if (aa == bb) return;
        if (rank[bb] > rank[aa]) swap(aa, bb);
        parent[bb] = aa;
        rank[aa] += rank[bb];
    }

    int get_rank(int a) {
        return rank[find(a)];
    }

    union_find(int n = 0) {
      init(n);
    }
};

// https://www.hackerrank.com/challenges/maximum-cost-queries

int main() {
	int N, Q; cin >> N >> Q;

    set<ll> weights;
    vector<pair<ll, pair<int, int>>> nodes;

    for (int i = 0; i < N - 1; i++) {
        ll u, v, w; cin >> u >> v >> w;
        weights.insert(w);
        nodes.push_back({w, {u, v}});
    }

    vector<pair<int, int>> queries(Q);

    for (int i = 0; i < Q; i++) {
        ll l, r; cin >> l >> r;
        weights.insert(l);
        weights.insert(r);
        queries[i] = {l, r};
    }

    int c = 0;
    unordered_map<int, int> T;

    for (auto v : weights) {
        T[v] = c++;
    }

    fenwick fwt(c);
    union_find uf(N + 1);

    sort(nodes.begin(), nodes.end());

    for (auto &g : nodes) {
        ll w = T[g.first];
        ll u = g.second.first;
        ll v = g.second.second;

        fwt.add(w, (ll)uf.get_rank(u) * (ll)uf.get_rank(v));
        uf.merge(u, v);
    }

    for (auto &v : queries) {
        cout << fwt.sum_range(T[v.first], T[v.second]) << endl;
    }

	return 0;
}

