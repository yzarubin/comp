#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        string s1, s2; cin >> s1 >> s2;
        int t1 = 0, t2 = 0;
        
        if (s1.substr(0, 2) != "12") t1 += stoi(s1.substr(0, 2)) * 60;
        if (s2.substr(0, 2) != "12") t2 += stoi(s2.substr(0, 2)) * 60;

        t1 += stoi(s1.substr(3, 2));
        t2 += stoi(s2.substr(3, 2));
        
        if (s1[5] == 'P') t1 += 12 * 60;
        if (s2[5] == 'P') t2 += 12 * 60;
        printf("%s\n", t1 < t2 ? "First" : "Second");
    }
   
    return 0;
}
