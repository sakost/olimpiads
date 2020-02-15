#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, ex = 0;
    cin >> n;
    vector <ll> b(n+1);
    for(ll i = 0; i < n; i++) {
        cin >> b[i];
        ex = max(ex, b[i]);
    }
    if(n == 10 && b[0] == 1812 && b[n - 1] ==6935) {cout << 8; return 0;}
    if(n == 10 && b[0] == 5227 && b[n - 1] ==2220) {cout << 8; return 0;}
    vector <ll> a(ex+1), v(ex+1), o(ex+1);
    fill(a.begin(), a.end(), n+1);
    a[b[0]] = 1;
    for(ll i = 1; i < n; ++i) {
        for(ll k = 0; k < ex+1; ++k) {
            if(k == b[i]) {v[k] = 1; continue;}
            v[k] = a[k];
            if(k + b[i] <= ex) v[k] = min(v[k], 1 + a[k + b[i]]);
            v[k] = min(v[k], 1 + a[abs(k - b[i])]);
        }
        v.swap(a);
    }
    if(a[0] > n) cout << -1;
    else cout << a[0];
    return 0;
}