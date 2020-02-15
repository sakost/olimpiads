#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll mex(vector <ll> &a) {
    set<ll> b(a.begin(), a.end());
    for (ll i=0; ; ++i)
        if (!b.count(i))
            return i;
}

void heapofdiv(ll n) {

    for(ll i = 2; i <= n; i++) {
        if(n % i == 0) {

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, amount = 0;
    cin >> n;
    vector <ll> divs;
    while (n % 2 == 0)
    {
        divs.push_back(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            divs.push_back(i);
            n = n/i;
        }
    }
    if (n > 2)
        divs.push_back(n);


    ll g = 0, count = 1;
    for(ll i = 1; i < divs.size(); i++) {
        if(divs[i] != divs[i - 1]) {
            g ^= count;
            count = 1;
        }
        else {
            count++;
        }
    }
    g ^= count;
    g == 0 ? cout << 2 : cout << 1;
    return 0;
}