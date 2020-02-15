#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(a == 0) {x = 0, y = 1; return b;}
    ll xx, yy, g;
    g = exgcd(b%a, a, xx, yy);
    x = yy - xx*(b/a);
    y = xx;
    return x;}

ll modulo(ll a, ll b) {
    return (b + a%b) % b;}

int main() {
    ll t, ans = 0, useless, cvl = 0, bqvl, tmp = 1e9, left, right, add;
    cin >> t;
    map<ll, ll> mp;
    while(t--) {
        cin >> left >> right >> add;
        mp[left] += add, mp[right+1] -= add;}
    for(auto gr = mp.begin(); next(gr) != mp.end(); gr++) {
        cvl += (gr->second) % MOD; cvl %= MOD;
        bqvl = modulo((gr->first % MOD + (next(gr)->first-1) % MOD) % MOD *
                      ((next(gr)->first-1) % MOD - gr->first % MOD + 1) % MOD
                      * exgcd(2, MOD, t, useless), MOD) *
               abs(cvl) % MOD * abs(cvl) % MOD;
        ans += (bqvl); ans %= MOD;}
    cout << ans;
}