#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'X') printf("%d,%d",i,j);
        }
    }
    return 0;
}
