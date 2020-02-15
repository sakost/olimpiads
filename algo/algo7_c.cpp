#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, res = 0, x; cin >> n;
    vector <ll> v(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
        //res += v[i];
    }


    for(ll i = 0; i < n; i++) {
        ll mx = v[i];
        for(ll j = i; j < n; j++) {
            if(v[j] > mx)
                mx = v[j];
            res += mx;
        }
    }
    cout << res;
}