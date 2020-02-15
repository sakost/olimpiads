#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 1000000007
#define MAX 100005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    ll n, m;
    cin >> a >> b;
    n = a.size(), m = b.size();

    vector <vector <ll>> dp(n + 1, vector <ll> (m+1));

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j-1]));
        }
    }

    ll ans = 0;
    for(ll j = 0; j <= m; j++)
    {
        ans = max(ans, dp[n][j]);
    }
    cout << ans;

    return 0;
}