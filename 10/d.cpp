#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define EPS 1e-12
using namespace std;

struct point { double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y; }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y); }

struct line {
    double a, b, c;
    bool operator == (line other) const {
        return (fabs(a - other.a) < EPS) && (fabs(b - other.b) < EPS) && (fabs(c - other.c) < EPS);
    }
};

void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
        l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    } }

bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true; }
struct vec { double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {} };
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s); }

point translate(point p, vec v) {
    return point(p.x + v.x , p.y + v.y); }

double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c); }

int main() {
    ll R, N, ans = 1, uje = 0; cin >> N >> R;
    double x1, x2, y1, y2;
    vector <line> v;
    while(N--) {
        cin >> x1 >> y1
            >> x2 >> y2;
        line l; point a;
        pointsToLine({x1, y1}, {x2, y2}, l);
        double dis = distToLine({0, 0}, {x1, y1}, {x2, y2}, a);
        if((R - dis) > EPS) {
            for(ll i = 0; i < v.size(); i++)
                if(l == v[i]) {uje = 1; break;}

            if(!uje) {
                ans++;
                set <point> s;
                for(ll i = 0; i < v.size(); i++) {
                    point pinter;
                    if(areIntersect(l, v[i], pinter)) {
                        if(s.count(pinter) == 0) {
                            if((-1 * pinter.x * pinter.x - pinter.y * pinter.y + R * R) > EPS)
                                ans++;

                            s.insert(pinter);
                        }
                    }
                }
                v.push_back(l);
            }
        }
        uje = 0;
        cout << ans << endl;
    }
    return 0;
}