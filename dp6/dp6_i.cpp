#include <bits/stdc++.h>
#define MOD 10000000007
#define ll long long
#define ld long double
using namespace std;

long long int fact(long long int N) {
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

struct pt {
    ll x, y;
};

long long int powermod(long long int base, long long int power) {
    if (power == 0) {
        return 1;
    }
    else {
        long long int cur = powermod(base, power / 2);
        cur = cur * cur;
        cur = cur % MOD;
        if (power % 2 == 1)
            cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

struct N {
    ld range;
    pt p;
};

long long int cnk(long long int n, long long int k) {
    return fact(n) / (fact(k) * fact(n - k));
}

ld hyp(pt b, pt e) {
    return sqrt((e.x-b.x)*(e.x-b.x) + (e.y-b.y)*(e.y-b.y));
}

int main()
{
    ll n, distoa = -10e9, distob = distoa, distoc = distoa, distod = distoa;
    N pN, vN, hlpng;
    pt b, e, AA, AB, BA, BC;
    cin >> n >> b.x >> b.y >> e.x >> e.y;
    pN.range = vN.range = hyp(b, e), pN.p = e, vN.p = b;
    while(n != 1) {
        n--;
        cin >> b.x >> b.y >> e.x >> e.y;
        if(vN.range + hyp(vN.p, b)<pN.range + hyp(pN.p, b))
            hlpng = {vN.range + hyp(vN.p, b) + hyp(b, e), e};
        else
            hlpng = {pN.range + hyp(pN.p, b) + hyp(b, e), e};
        if(vN.range + hyp(vN.p, e) < pN.range + hyp(pN.p, e))
            vN = {vN.range + hyp(vN.p, e) + hyp(e, b), b};
        else
            vN = {pN.range + hyp(pN.p, e) + hyp(e, b), b};
        pN = hlpng;
    }
    ld ans = min(pN.range, vN.range);
    cout << fixed << setprecision(100) << ans;
    return 0;
}