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

bool eld(const ld &one, const ld &other){
    return fabsl(one-other) <= eps;
}

#define x fs
#define y sc
typedef pair<ld, ld> point;
typedef point vec;

bool operator==(const point &one, const point &other){
    return (eld(one.x, other.x) && (eld(one.y, other.y)));
}

vec p2v(const point &p1, const point &p2){
    return {p2.x-p1.x, p2.y-p1.y};
}

//#undef x
//#undef y

struct line{
    ld a=0, b=0, c=0;
};

ld dot(const vec &v1, const vec &v2);

ld sq(const vec &v);

vec operator*(const vec &v, ld s);


ld dist(const point &p1, const point &p2);

bool operator==(const line &one, const line &other){
    return (eld(one.a, other.a) && eld(one.b, other.b)) && eld(one.c, other.c);
}

bool operator<(const line &l1, const line &l2){
    if(l1.a == l2.a){
        if(l1.b == l2.b){
            return l1.c < l2.c;
        }
        return l1.b < l2.b;
    }
    return l1.a < l2.a;
}

line p2l(const point &p1, const point &p2){
    line l;
    if(eld(p1.x, p2.x)){
        l.a =1.l;
        l.b=0.l;
        l.c=-(ld)p1.x;
    }else{
        l.a = -(ld)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.l;
        l.c = -(ld)(l.a*p1.x) - p1.y;
    }
    return l;
}

ld dist2line(const point &p, const point &a, const point &b){
    vec ap = p2v(a, p), ab = p2v(a, b);
    ld u = dot(ap, ab) / sq(ab);
    vec cc = ab*u;
    point c = {cc.x + a.x, cc.y + a.y};
    return dist(p, c);
}

ld dist(const point &p1, const point &p2) {
    return hypot(p1.x - p2.x, p1.y-p2.y);
}

ld sq(const vec &v) {
    return dot(v, v);
}

ld dot(const vec &v1, const vec &v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

vec operator*(const vec &v, ld s){
    return vec(v.x * s, v.y * s);
}

bool linesPar(const line &l1,const line &l2) {
    return eld(l1.a, l2.a) && eld(l1.b, l2.b);
}

bool inter(const line &l1, const line &l2, point &p) {
    if (linesPar(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (!eld(l1.b, 0)) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}


//#define endl '\n'

void solve() {
    ll r, n;
    ld x1, y1, x2, y2;
    ll ans(1);
    cin >> n >> r;
    set<line> lines;
    set<point> ps;
    fori(0, n){
        cin >> x1 >> y1 >> x2 >> y2;
        line l = p2l({x1, y1}, {x2, y2});
        ld dist = dist2line({0, 0}, {x1, y1}, {x2, y2});
        point pInter;
        if(r - dist > eps){
            forel(lines){
                if(el == l)
                    goto print_ans;
            }
            ans++;
            forel(lines){
                if(inter(l, el, pInter)){
                    if(ps.count(pInter) == 0){
                        if((ld)r*r-pInter.x * pInter.x - pInter.y * pInter.y > eps)
                            ans++;
                        ps.insert(pInter);
                    }
                }
            }
        }
        print_ans:
        lines.insert(l);
        cout << ans << endl;
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