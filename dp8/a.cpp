#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll powermod(ll base, ll power) {
    if (power == 0) {
        return 1;
    }
    else {
        ll cur = powermod(base, power / 2);
        cur = cur * cur;
        cur = cur % MOD;
        if (power % 2 == 1)
            cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    if(k >= n)
        cout << powermod(2, n-1);
    else {
        vector <ll> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;
        for(ll i = 2; i <= k; i++)
            dp[i] = powermod(2, i - 1) % MOD;

        for(ll i = k + 1; i <= n; i++) {
            dp[i] = dp[i - 1] * 2 - dp[i - k - 1] + MOD * ((dp[i - 1] * 2 - dp[i - k - 1]) < 0);
            dp[i] %= MOD;
            //cout << dp[i]
        }
        cout << dp[n];




        /*for(ll i = k + 1; i <= n; i++) {
            for(ll j = 1; j <= min(k, i); j++) {
                dp[i] += dp[i - j];
            }
            dp[i] = dp[i] % MOD;
        }
        cout << dp[n];*/
    }
}