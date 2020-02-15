//
// Created by sakost on 10.12.2019.
//

#include <bits/stdc++.h>

#pragma optimize("tg", on)


using namespace std;

// definitions
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;


//const ll p = 31;
const ll P = 1000000007;
const ld INFLD = numeric_limits<ld>::max();
const ll INFL = numeric_limits<ll>::max();
const int INF = numeric_limits<int>::max();
const ld eps = numeric_limits<ld>::epsilon();
const ld pi = 3.14159265358979323846264338327950288419716939937510;
const ld d2r = pi / 180;
const ld r2d = 180 / pi;

#define timeit clock_t _begin = clock();
#define endtimeit clock_t _end = clock(); cerr << "Elapsed seconds: " << double(_end - _begin) / CLOCKS_PER_SEC << endl;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fori(k, n) for(ll i(k); i < n; ++i)
#define forj(k, n) for(ll j(k); j < n; ++j)
#define formi(n, k) for(ll i(n); i > k; --i)
#define sz size()
#define forel(a) for(auto &el: a)
#define srt(a) sort(a.begin(), a.end())
#define srtf(a, func) sort(a.begin(), a.end(), func)
#define rvrs(a) reverse(a.begin(), a.end())
#define bg begin()
#define fs first
#define sc second
#ifdef _ONPC_
#define what(x) cerr << #x << " = " << x << endl
#else
#define what(x)
#endif


// simple functions
template<typename T>
inline T gcd(T a, T b) {
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

template<typename T>
inline T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    c.resize(n, vector<int>(n, 0));
    fori(0, n){
        forj(0, n){
            cin >> c[i][j];
        }
    }
    vector<int> path(n-1, 0);
    iota(path.begin(), path.end(), 1);
    int res = INF;
    do{
        int cur = 0;
        int prev = 0;
        forel(path){
            cur += c[prev][el];
            prev = el;
        }
        res = min(res, cur);
    } while(next_permutation(path.bg, path.end()));
    cout << res;
}

signed main() {
#ifdef _ONPC_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#define TIMEIT
    timeit
#endif // _ONPC_

    fastIO;
    int t(1);
//    cin >> t; //////////////////////////////// UNCOMMENT IF WITH TESTS ///////////////////////////////////////
    fori(0, t)solve();

#ifdef TIMEIT
    endtimeit
#endif // TIMEIT
    return 0;
}