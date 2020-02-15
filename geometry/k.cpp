#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct pt {
    ld x, y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(ld d) {return {x*d, y*d};}
    pt operator/(ld d) {return {x/d, y/d};}
    bool operator< (pt other)
    {
        if (x != other.x)
            return x < other.x;
        else
            return y < other.y;
    }
};

ld dist(pt a, pt b) {
    return sqrtl((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

struct vec { ld x, y;  // name: `vec' is different from STL vector
    vec(ld _x, ld _y) : x(_x), y(_y) {} };

ld dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

ld norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

vec toVec(pt a, pt b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }

double angle(pt a, pt o, pt b) {  // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool byangle (const pt &a, const pt &b) {
    //return angle(a, {0, 0}, {1000, 1000}) > angle(b, {0, 0}, {1000, 1000});
    return (a.x * b.y - a.y * b.x) < 0;
}

int main() {
    ld ans = 0, b1, b2, h;
    pt a, b;
    ll n; cin >> n;
    vector <pt> v(n);
    for(ll i = 0; i < n; i++)
        cin >> v[i].x >> v[i].y;

    sort(v.begin(), v.end(), byangle);

    a = {0, 0};
    for(ll i = 0; i < n; i++) {
        b = v[i] + a;
        b1 = a.y, b2 = b.y - 0, h = b.x - a.x;
        ans += (b1 + b2) * h;
        //ans += a.x * b.y - b.x * a.y;
        a = b;
    }
    //ans += a.x * v[0].y - a.y * v[0].x;

    cout << (ll) ans;
}