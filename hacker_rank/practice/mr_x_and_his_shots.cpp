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

// https://www.hackerrank.com/challenges/x-and-his-shots

int main() {
    int N, M; cin >> N >> M;

    set<int> s;
    vector<pair<int, int>> a1(N), a2(M);

    for (int i = 0; i < N; i++) {
        cin >> a1[i].first >> a1[i].second;
        s.insert(a1[i].first);
        s.insert(a1[i].second);
    }

    for (int i = 0; i < M; i++) {
        cin >> a2[i].first >> a2[i].second;
        s.insert(a2[i].first);
        s.insert(a2[i].second);
    }

    int g = 0;
    unordered_map<int, int> T;
    for (auto v : s) T[v] = g++;

    fenwick beg(g + 1);
    fenwick end(g + 1);

    for (auto &v : a1) {
        beg.add(T[v.first], 1);
        end.add(T[v.second], 1);
    }

    int ans = 0;

    for (auto &v : a2) {
        ans += a1.size() - end.sum_range(0, T[v.first] - 1) - beg.sum_range(T[v.second] + 1, g + 1);
    }

    cout << ans << endl;

    return 0;
}

