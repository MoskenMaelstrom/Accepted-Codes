// Problem: B. Nana Likes Polygons
// Contest: Codeforces - The 2024 International Collegiate Programming Contest in Hubei Province, China
// URL: https://codeforces.com/gym/105139/problem/B
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const double eps = 1e-9;

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

double area(Point a, Point b, Point c) {
    return cross(b - a, c - a);
}

void solve()
{
	int n;
	cin>>n;
	vector<Point> a(n);
	double ans=1e9;
	for(int i=0;i<n;i++) cin>>a[i].x>>a[i].y;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			for(int k=j+1;k<n;k++) {
				double s=fabsl(area(a[i],a[j],a[k])/2);
				if (sign(s)) ans=min(ans,s);
			}
		}
	}
	if (cmp(ans,1e9) == 0 or sign(ans) == 0) cout<<"-1\n";
	else cout<<ans<<"\n";
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







