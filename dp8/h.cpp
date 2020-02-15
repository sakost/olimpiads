#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll N, W, C = 0, res;
    cin >> N >> W;
    vector<ll> value(N + 1, 0);
    vector<ll> w(N + 1, 0);
    for (ll i = 1; i <= N; i++)
    {
        cin >> w[i] >> value[i];
        C += value[i];
    }
    vector<ll> cur(C + 1, 0), prev(C + 1, W + 1);
    prev[0] = 0;
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = value[i]; j <= C; j++)
        {
            cur[j] = min(prev[j], prev[j - value[i]] + w[i]);
        }
        for (ll j = 0; j < value[i]; j++)
        {
            cur[j] = prev[j];
        }
        swap(cur, prev);
    }
    for (ll i = 0; i <= C; i++)
    {
        if (prev[i] <= W)
        {
            res = i;
        }
    }
    cout << res;
    return 0;
}