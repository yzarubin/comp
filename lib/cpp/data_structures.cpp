
// disjoint set
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

    union_find(int n = 0) {
      init(n);
    }
};

// BIT that accounts for the 1-offset
struct fenwick {
    vector<long long> tree;
    fenwick(int n = 0) {
        init(n);
    }

    void init(int n) {
        tree.assign(n + 1, 0);
    }

    void add(int i, long long val) {
        i++;
        while (i < tree.size()) {
            tree[i] += val;
            i += i & -i;
        }
    }

    ll query(int r) {
        r++;
        ll sum = 0;
        int sum = 0;
        while (r > 0){
            sum += tree[r];
            r -= (r & -r);
        }
        return sum;
    }

    ll range(int l, int r) {
        l++, r++;
        return query(r) - query(l - 1);
    }
};


// BIT with range that accounts for the 1-offset
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


