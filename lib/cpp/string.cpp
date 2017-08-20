
vector<int> create_prefix_table(string pattern) {
    vector<int> kmp(pattern.size());
    int pos = 2, cand = 0;
    kmp[0] = -1;
    while (pos < pattern.size()) {
        if (pattern[pos - 1] == pattern[cand]) {
            kmp[pos++] = ++cand;
        } else if (cand > 0) {
            cand = kmp[cand];
        } else {
            pos++;
        }
    }
    return kmp;
}

vector<int> kmp_multi_match(string &s, string &pattern, vector<int> &prefix_table) {
    vector<int> res;
    if (s.size() < pattern.size()) return res;

    int start = 0; // start of the pattern
    int pos = 0;
    while (pos + start < s.size()) {
        if (s[start + pos] != pattern[pos]) {
            start = start + pos - prefix_table[pos];
            pos = prefix_table[pos] > -1 ? prefix_table[pos] : 0;
        } else if (++pos == pattern.size()) { // match
            res.push_back(start);
            start++;
            pos = 0;
        }
    }
    return res;
}

