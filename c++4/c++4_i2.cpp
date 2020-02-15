//
// Created by sakost on 22.12.2019.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, amount = 0;
    cin >> N;
    vector <ll> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            amount += lower_bound(v.begin(), v.end(), v[i] + v[j]) - v.begin() - j - 1;
            //cout << "for i, j = " << i << ", " << j << "; k = " << lower_bound(v.begin(), v.end(), v[i] + v[j]) - v.begin() << endl;
        }
    }
    cout << amount;
    return 0;
}