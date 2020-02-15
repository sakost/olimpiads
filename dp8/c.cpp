#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int MatrixChainOrder(vector <ll> p, ll n)
{

    int m[n][n];

    int i, j, k, L, q;

    // cost is zero when multiplying
    // one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] +
                    p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

int main()
{

    vector <ll> arr;
    ll n, flag = 1, r, c;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> r >> c;
        if(i == 0) {
            arr.push_back(r);
            //arr.push_back(c);
        }
        if(!flag) {
            arr.push_back(r);
            flag = 0;
        }
        else {
            arr.push_back(c);
            flag = 1;
        }
    }
    /*for(auto x : arr) {
        cout << x << " ";
    }*/
    cout << MatrixChainOrder(arr, n+1);


    return 0;
}