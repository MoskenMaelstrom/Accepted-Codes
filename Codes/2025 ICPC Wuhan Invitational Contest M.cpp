// Problem: M. Flight Tracker
// Contest: Codeforces - 2025 ICPC Wuhan Invitational Contest (The 3rd Universal Cup. Stage 37: Wuhan)
// URL: https://codeforces.com/gym/105901/problem/M
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const double pi=acosl(-1.0);
const double eps = 1e-9;

double Acos(double x) {
	if(x < -1) return pi;
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
    double x, y, z;
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    Point operator+(const Point& b) const { return Point(x + b.x, y + b.y, z + b.z); }
    Point operator-(const Point& b) const { return Point(x - b.x, y - b.y, z - b.z); }
    Point operator*(double k) const { return Point(x * k, y * k, z * k); }
    Point operator/(double k) const { return Point(x / k, y / k, z / k); }

    bool operator==(const Point& b) const { 
        return cmp(x, b.x) == 0 && cmp(y, b.y) == 0 && cmp(z, b.z) == 0; 
    }

    bool operator<(const Point& b) const {
        if (cmp(x, b.x) != 0) return x < b.x;
        if (cmp(y, b.y) != 0) return y < b.y;
        return z < b.z;
    }
};
typedef Point Vector;

// 点积
double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// 叉积
Vector cross(Vector a, Vector b) {
    return Vector(a.y * b.z - a.z * b.y, 
                    a.z * b.x - a.x * b.z, 
                    a.x * b.y - a.y * b.x);
}

// 向量模长
double get_length(Vector a) {
    return sqrt(dot(a, a));
}

// 向量单位化
Vector unit(Vector a) {
    double l = get_length(a);
    if (sign(l) == 0) return a;
    return a / l;
}

// 两个非零向量的夹角 [0, PI]
double get_angle(Vector a, Vector b) {
    return Acos(dot(a, b) / (get_length(a) * get_length(b)));
}

void solve()
{	
	int r;
	cin>>r;
	Point v,a,b;
	cin>>v.x>>v.y>>v.z;	
	cin>>a.x>>a.y>>a.z;
	cin>>b.x>>b.y>>b.z;
	Vector v1=cross(a,b);
	if (dot(v,cross(b,v1)) > 0 and dot(v,cross(a,v1)) < 0) {
		cout<<fixed<<setprecision(10)<<fabsl(pi/2-get_angle(v,v1))*r<<"\n";
	}
	else cout<<fixed<<setprecision(10)<<min(get_angle(b,v),get_angle(a,v))*r<<"\n";
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







