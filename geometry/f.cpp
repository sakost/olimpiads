#include <bits/stdc++.h>
#define ld long double
#define ll long long
using namespace std;

struct pt {
    ld x,y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(ld d) {return {x*d, y*d};}
    pt operator/(ld d) {return {x/d, y/d};} // only for floatingpoint
};

bool operator==(pt a, pt b) {return a.x == b.x && a.y == b.y;}
bool operator!=(pt a, pt b) {return !(a == b);}

ld sql(pt a, pt b, pt c) {
    return (c.x - a.x) * (c.y - b.y) - (c.x - b.x) * (c.y - a.y);
}

bool intersect_1 (ll a, ll b, ll c, ll d) {
    if (a > b)  swap (a, b);
    if (c > d)  swap (c, d);
    return max(a,c) <= min(b,d);
}

bool intersect (pt a, pt b, pt c, pt d) {
    return intersect_1 (a.x, b.x, c.x, d.x)
           && intersect_1 (a.y, b.y, c.y, d.y)
           && sql(a,b,c) * sql(a,b,d) <= 0
           && sql(c,d,a) * sql(c,d,b) <= 0;
}

ld dot(pt a, pt b) {
    return (a.x * b.x + a.y * b.y);
}

ld distance(pt a, pt b) {
    return 1.0 * sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld distancetoline(pt p, pt q, pt a) {
    ld area = abs(sql(a, p, q));
    ld d = distance(p, q); //
    return 1.0 * area / d;
}

ld distancetosegment(pt p, pt q, pt a) {
    if(dot(q-p, a-p) < 0) {
        return distance(a, p);
    }
    if(dot(p-q, a-q) < 0) {
        return distance(a, q);
    }
    return distancetoline(p, q, a);
}

int main() {
    ll t;
    pt p, q, r, s;
    ld ans1 = -1, ans2 = -1;
    cin >> t;
    while(t--) {
        cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y >> s.x >> s.y;
        if(intersect(p, q, r, s)) {
            cout << 0 << endl;
        }
        else {
            ans1 = min(distancetosegment(p, q, r), distancetosegment(p, q, s));
            ans2 = min(distancetosegment(r, s, p), distancetosegment(r, s, q));
            cout << setprecision(50) << min(ans1, ans2) << endl;
        }
    }
    return 0;
}