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

template<typename T>
struct SegmentTree {
    size_t n;
    vector<T> data;
    function<T(const T &, const T &)> operation;

    explicit SegmentTree(const vector<T> &a, function<T(const T &, const T &)> op) {
        n = a.sz;
        operation = op;
        data.resize(4 * n);
        treeBuild(a, 0, 0, n - 1);
    }

    void treeBuild(const vector<T> &a, size_t i, size_t tl, size_t tr) {
        if (tr - tl == 0) {
            data[i] = a[tl];
            return;
        }
        size_t tm = (tr + tl) / 2;
        treeBuild(a, 2 * i + 1, tl, tm);
        treeBuild(a, 2 * i + 2, tm + 1, tr);
        data[i] = operation(data[2 * i + 1], data[2 * i + 2]);
    }

    T query(size_t a, size_t b) {
        return query(0, 0, n - 1, a, b);
    }

    T query(size_t i, size_t sl, size_t sr, size_t ql, size_t qr) {
        if ((qr == sr) && (ql == sl)) {
            return data[i];
        }
        size_t sm = (sl + sr) / 2;
        if (qr <= sm) return query(i * 2 + 1, sl, sm, ql, min(qr, sm));
        if (ql > sm) return query(i * 2 + 2, sm + 1, sr, max(ql, sm + 1), qr);
        return operation(query(2 * i + 1, sl, sm, ql, min(qr, sm)), query(i * 2 + 2, sm + 1, sr, max(ql, sm + 1), qr));
    }

    void modify(size_t p, T x) {
        modify(0, 0, n - 1, p, x);
    }

    void modify(size_t i, size_t sl, size_t sr, size_t p, T x) {
        if (sl == sr) {
            data[i] = operation(x, data[i]);
            return;
        }
        size_t sm = (sl + sr) / 2;
        if (p <= sm) modify(2 * i + 1, sl, sm, p, x);
        else modify(2 * i + 2, sm + 1, sr, p, x);
        data[i] = operation(data[2 * i + 1], data[2 * i + 2]);
    }
};

template<typename T>
T maxll(const T &a, const T &b) {
    return b +a;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    cin >> a[0];
    fori(1, n) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    SegmentTree<ll> sg(a, maxll<ll>);
    sg.data.resize(4 * n, 0ll);
    int k;
    cin >> k;
    fori(0, k) {
        ll q;
        cin >> q;

        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll el = sg.query(l, r);
        cout << el << endl;
    }
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