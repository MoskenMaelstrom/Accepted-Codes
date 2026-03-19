// Problem: L. Stapler
// Contest: Codeforces - 2025 ICPC Asia Taiwan Online Programming Contest
// URL: https://codeforces.com/gym/106084/problem/L
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const double eps = 1e-9;
const double PI = acosl(-1.0);

double Acos(double x) {
	if(x < -1) return PI;
	if(x > 1) return 0;
	return acosl(x);
};

int sign(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

int cmp(double x, double y) {
    if (fabs(x - y) < eps) return 0;
    return x < y ? -1 : 1;
}

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    Point operator+(const Point& b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point& b) const { return Point(x - b.x, y - b.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
    Point operator/(double k) const { return Point(x / k, y / k); }
    
    bool operator==(const Point& b) const { 
        return cmp(x, b.x) == 0 && cmp(y, b.y) == 0; 
    }
    
    bool operator<(const Point& b) const {
        int c = cmp(x, b.x);
        if (c != 0) return c == -1; 
        return cmp(y, b.y) == -1;   
    }
};
typedef Point Vector;

double cross(Vector a, Vector b) {
    return a.x * b.y - b.x * a.y;
}

bool f(Point a1, Point a2, Point b1, Point b2) {
    if (min(a1.x, a2.x) > max(b1.x, b2.x) || max(a1.x, a2.x) < min(b1.x, b2.x) ||
        min(a1.y, a2.y) > max(b1.y, b2.y) || max(a1.y, a2.y) < min(b1.y, b2.y)) {
        return false;
    }
    
    double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
    double c3 = cross(b2 - b1, a1 - b1), c4 = cross(b2 - b1, a2 - b1);
    return sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0;
}

void solve()
{
	Point p1,p2,p3,p4;
	cin>>p1.x>>p1.y>>p4.x>>p4.y;
	p3.x=p1.x,p3.y=p4.y;
	p2.x=p4.x,p2.y=p1.y;
	Point b1,b2;
	cin>>b1.x>>b1.y>>b2.x>>b2.y;
	if (f(p1,p2,b1,b2) or f(p2,p4,b1,b2) or f(p3,p4,b1,b2) or f(p1,p3,b1,b2)) cout<<"STOP\n";
	else if (p1.x <= b1.x and b1.x <= p4.x and 
			 p1.y <= b1.y and b1.y <= p4.y and 
			 p1.x <= b2.x and b2.x <= p4.x and 
			 p1.y <= b2.y and b2.y <= p4.y) cout<<"STOP\n";
	else cout<<"OK\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







