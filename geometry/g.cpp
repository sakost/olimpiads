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

double dist(pt p1, pt p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y); }

ld f(pt x, pt fire, pt base) {
    return dist(base, x) + dist(x, fire);
}

pt ternary_search(pt a, pt b, pt fire, pt base) {
    ld l = 0, r = 1, l1, r1;
    for(ll i = 0; i < 1000; i++) {
        l1 = l + (r - l) / 3;
        r1 = r - (r - l) / 3;
        if(f( a + (b-a) * l1, fire, base ) < f( a + (b-a) * r1, fire, base ))
            r = r1;
        else
            l = l1;
    }
    return a + (b-a) * l1;
}

void display (pt a) {
    cout << a.x << a.y;
}

int main() {
    pt base, a, b, c, fire, p1, p2, p3;
    ld ans1, ans2, ans3;
    cin >> base.x >> base.y >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    ll m; cin >> m;
    for(ll i = 0; i < m; i++) {
        cin >> fire.x >> fire.y;
        p1 = ternary_search(a, b, fire, base);
        p2 = ternary_search(b, c, fire, base);
        p3 = ternary_search(a, c, fire, base);
        ans1 = f(p1, fire, base);
        ans2 = f(p2, fire, base);
        ans3 = f(p3, fire, base);
        cout << fixed << setprecision(50);
        if(ans1 <= ans2 && ans1 <= ans3)
            cout << p1.x << " " << p1.y;
        else
        if(ans2 <= ans1 && ans2 <= ans3)
            cout << p2.x << " " << p2.y;
        else
            cout << p3.x << " " << p3.y;
        cout << endl;
    }
}