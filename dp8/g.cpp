#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main() {
    ll n; cin >> n;
    vector <vector <ll>> dp(n + 1, vector <ll> (n + 2, 0));
    dp[n][n+1] = 1;
    for(ll left = n - 1; left >= 0; left--) {
        for(ll min = 1; min <= n + 1; min++) {
            dp[left][min] = (dp[left][min-1]+dp[left][min]) % MOD;
            if(min + left <= n) {
                dp[left][min] = (dp[left][min] + (dp[left + min][n + 1] -
                                                  dp[min + left][min]) % MOD) % MOD;
            }
            if(dp[left][min] < 0) dp[left][min] += MOD;
        }
    }
    ll res = dp[0][n+1];
    cout << res % MOD;
}