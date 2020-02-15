#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m[101][101] = {0}, ans;
    cin >> n;
    for(ll r = 1; r <= n; r++) {
        for(ll l = 1; l <= r; l++) {
            cin >> m[r][l];
        }
    }
    if(n == 1) {
        cout << m[1][1];
        return 0;
    }

    for(ll r = 2; r <= n; r++) {
        for(ll l = 1; l <= r; l++) {
            m[r][l] += max(m[r-1][l], m[r-1][l-1]);
        }
    }

    for(ll l = 1; l <= n; l++) {
        ans = max(ans, m[n][l]);
    }

    cout << ans;
    return 0;
}