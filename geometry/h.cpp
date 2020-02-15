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

bool operator<(const pt &a, const pt &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

ld dist(pt a, pt b) {
    return ((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int main() {
    ld ans = 0;
    ld dx, dy, dis;
    pt a, b, c, d;
    ll n; cin >> n;
    vector <pt> p(n);
    for(ll i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    set <pt> s(p.begin(), p.end());

    for(ll i = 0; i < n - 1; i++) {
        for(ll j = i + 1; j < n; j++) {
            a = p[i], b = p[j];
            dis = dist(a, b), dx = abs(a.x - b.x), dy = abs(a.y - b.y);
            c = {min(a.x,b.x) - dy, min(a.y,b.y) + dx}, d = {max(a.x, b.x) + dx, max(a.y, b.y) - dy};
            if(s.count(c) && s.count(d))
                ans = max(ans, dis );
            c = {min(a.x,b.x) + dy, min(a.y,b.y) - dx}, d = {max(a.x, b.x) + dy, max(a.y, b.y) - dx};
            if(s.count(c) && s.count(d))
                ans = max(ans, dis );
        }
    }

    cout << (ll)ans;
}