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
enable_if_t < is_integral_v < T >, T >
inline gcd(T a, T b) {
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

template<typename T>
enable_if_t < is_integral_v < T >, T >
inline lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

template <class T>
struct tData{
    T min, max;
};

template<class T>
class DSU{
public:
    explicit DSU()= default;

    void make_set(T v){
        parent[v] = v;
        size[v] = 1;
        data[v] = {v, v};
    }

    T find_set(T v){
        if(v == parent[v]){
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    T union_sets(T a, T b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
            if(size[a] < size[b]){
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
            data[a] = {min(data[b].min, data[a].min), max(data[b].max, data[a].max)};
        }
        return a;
    }

    T count_size(T a){
        return size[a];
    }

    tData<T> getData(T v){
        return data[v];
    }

private:
    map<T, T> parent;
    map<T, size_t> size;
    map<T, tData <T> > data;
};


using Graph = vector< vector< int > >;

struct Edge{
    ll weight;
    ll from, to;
};

bool operator<(const Edge &lhs, const Edge &rhs){
    return lhs.weight < rhs.weight || (lhs.weight == rhs.weight && lhs.from < rhs.from);
}

void solve() {
    int n;
    cin >> n;

    vector<ll> points(n);
    DSU<ll>dsu;

    for (int i = 0; i < n; ++i) {
        cin >> points[i];
        dsu.make_set(points[i]);
    }

    sort(points.begin(), points.end());

    vector<Edge> edges(n - 1);

    for (int i = 0; i < n-1; ++i) {
        Edge edge{};
        edge.from = points[i];
        edge.to = points[i+1];
        edge.weight = edge.to - edge.from;
        edges[i] = edge;
    }
    
    sort(edges.begin(), edges.end());

    for(auto edge: edges){
        if(dsu.find_set(edge.from) != dsu.find_set(edge.to)){
            auto data1 = dsu.getData(dsu.find_set(edge.from));
            auto data2 = dsu.getData(dsu.find_set(edge.to));
            cout << data1.min << ' ' << data1.max << ' ' << data2.min << ' ' << data2.max;
            cout << '\n';
            dsu.union_sets(edge.from, edge.to);
        }
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