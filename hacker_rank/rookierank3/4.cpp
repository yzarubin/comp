#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<ll> memo(1 << 21, -1);
    
    function<ll(ll, ll)> go = [&](ll k, ll sum) {
        if (memo[k] != -1) return memo[k];
        if (!k) return 0ll;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll g = 1 << i;
            if ((k & g) == g) {
                ll next = go(k ^ g, sum + nums[i]);
                ans = max(ans, next + sum % nums[i]);
            }
        }
        
        memo[k] = ans;
        return memo[k];
    };
    
    cout << go((1 << n) - 1, 0) << endl;
    
    return 0;
}
