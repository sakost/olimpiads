#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, amount;
    ld sum = 0;
    cin >> n >> amount;
    vector <ll> v(amount + 1);
    vector <ll> s(amount + 1, -1);
    for(int i = 1; i <= amount; i++) {
        cin >> v[i];
        sum += 1.0 / v[i];
    }
    sort(v.begin(), v.end());
    if(n == 1) {cout << v[1]; return 0;}

    ll t = v[1], c = 1;
    s[1] = 0;
    while(c < amount) {
        for(ll i = 1; i < v.size(); i++) {
            if(s[i] == -1) {
                if(c >= i)
                    s[i] = t;
            }
            else {
                if((t - s[i]) % v[i] == 0)
                {c++; s[i] = t;}
            }
        }

        if((c - 1) >= n) {
            cout << t;
            return 0;
        }

        t++;
    }


    n = n - c + 1;
    if(n == 1) {cout << v[1] + t; return 0;}

    ll l = -1, r = 100 * n, m;
    ll res;
    while(r - l > 1) {
        m = (r + l) / 2;
        res = 0;
        for(ll i = 1; i < v.size(); i++) {
            res += ((m + t) - s[i]) / v[i];
        }

        if(res >= n) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << r + t;
    return 0;
}