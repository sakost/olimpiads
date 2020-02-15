#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

long long int fact(long long int N) {
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

long long int cnk(long long int n, long long int k) {
    return fact(n) / (fact(k) * fact(n - k));
}

long long int powermod(long long int base, long long int power) {
    if (power == 0) {
        return 1;
    }
    else {
        long long int nmmntel = powermod(base, power / 2);
        nmmntel = nmmntel * nmmntel;
        nmmntel = nmmntel % MOD;
        if (power % 2 == 1)
            nmmntel = nmmntel * base;
        nmmntel = nmmntel % MOD;
        return nmmntel;
    }
}

ll n, m, answer;
vector<vector<ll>> f, arr;

ll solve(ll y, ll H) {
    if(H < 0 || H >= m || y < 0 || y >= n) return -2;
    if(arr[y][H] != -1) return arr[y][H];
    if(H == 0 && y == 0){arr[y][H] = f[y][H];return arr[y][H];}
    answer = max(solve(y+1, H-2),max(solve(y-1, H-2),max(solve(y-2, H-1),solve(y-2, H+1))));
    if(answer == -2) arr[y][H] = -2;
    else arr[y][H] = answer + f[y][H];
    return arr[y][H];
}

int main(){
    ll q = 1, temp = q;
    cin >> n >> m;
    temp *= q;
    temp *= n;
    f = vector<vector<ll>>(n, vector<ll>(m, 0));
    arr = vector<vector<ll>>(n, vector<ll>(m, -1));
    for(ll y = 0; y < n; ++y){
        for(ll H = 0; H < m; ++H){
            scanf("%lli", &f[y][H]);}
    }
    ll answer = 0, nmmntel;
    for(ll y = 0; y < n; ++y) {
        for(ll H = 0; H < m; ++H) {nmmntel = solve(y, H); if(nmmntel > answer)answer = nmmntel;
        }}
    cout << answer;
}