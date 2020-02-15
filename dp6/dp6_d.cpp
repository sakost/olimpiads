#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct info {
    ll price, prev, next;
};

int main()
{
    int n, k, minimal, d = 0, current, a = 0, b = 1, c = 2;
    cin >> n >> k;
    current = n;
    vector <info> v(n + 2);
    v[0] = {0, -1}, v[n] = {0, -1};
    for(ll i = 1; i < n; ++i) cin >> v[i].price;
    for(int i = 1; i < n+1; ++i) {
        minimal = i-1;
        for(int j = max(0, i-k); j < i-1; ++j) {
            if(v[j].price <= v[minimal].price)
                minimal = j;
        }
        v[i].prev = minimal;
        v[i].price = v[i].price + v[minimal].price;
    }
    v[current].next = -1;
    ++d;
    while(v[current].prev >= 0 && d++ && (b + c) != a) {
        v[v[current].prev].next = current, current = v[current].prev;
    }
    cout << v[n].price << " " << d << endl;
    for(ll i = 0; i >= 0; i = v[i].next) cout << i << " ";
    //
    return 0;
}