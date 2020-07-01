#include <bits/stdc++.h>
#define ll long long
#define blank -1

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n; cin >> n;

    vector <pair <int, int>> dv(15);
    dv[8] = {1, 6}, dv[9] = {1, 8}, dv[10] = {2, 2},
    dv[11] = {2, 6}, dv[12] = {2, 8}, dv[13] = {6, 8};

    vector <int> od(9);
    od[2] = 1, od[3] = 7, od[4] = 4, od[5] = 2, od[6] = 6, od[7] = 8;

    int t = n;

    if(t <= 7) {cout << od[t]; t = 0;}

    vector <int> ans;
    if(t % 7 == 0) {
        while(t) {
            //cout << 8;
            ans.push_back(8);
            t -= 7;
        }
    }
    while(t > 14) {
        //cout << 8;
        ans.push_back(8);
        t -= 7;
    }

    if(t) {
        ans.push_back(dv[t].first);
        ans.push_back(dv[t].second);
    }
    sort(ans.begin(), ans.end());
    int zeros_num = 0;
    for(int an : ans) {
        if(an == 0) {
            zeros_num++;
        }
        else {
            cout << an;
            for(int j = 0; j < zeros_num; j++)
                cout << 0;
            zeros_num = 0;
        }
    }


    cout << " ";

    // maxi
    if(n % 2 == 1) {
        cout << 7;
        n -= 3;
    }
    while(n > 0) {
        cout << 1;
        n -= 2;
    }
}