#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fact(ll n) {
    ll res = 1;
    while(n) {
        res *= n;
        n--;
    }
    return res;
}

ll cnk(ll n, ll k) {
    return fact(n) / (fact(k) * fact(n - k));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll first, second, count, good = 0;
    for(ll i = 0; i < n - 2; i++) {
        first = a[i];
        second = upper_bound(a.begin(), a.end(), k + a[i]) - a.begin() - 1;
        count = second - i + 1;
        if(count >= 3)
            good += (count - 1) * (count - 2) / 2;
    }
    cout << good;
}