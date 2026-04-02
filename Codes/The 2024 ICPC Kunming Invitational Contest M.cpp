#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    Point operator+(const Point& b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point& b) const { return Point(x - b.x, y - b.y); }
    Point operator*(int k) const { return Point(x * k, y * k); }
    
    bool operator==(const Point& b) const { 
        return x == b.x && y == b.y; 
    }
    
    bool operator<(const Point& b) const {
        if (x != b.x) return x < b.x; 
        return y < b.y;   
    }
};
typedef Point Vector;

i128 dot(Vector a, Vector b) {
    return (i128)a.x * b.x + (i128)a.y * b.y;
}

int cross(Vector a, Vector b) {
    return a.x * b.y - b.x * a.y;
}

int S(Point a, Point b, Point c) {
	return abs(cross(b - a, c - a));
}

bool check(Point p, Point a, Point b,int r) {
    Vector v1 = b - a;
    Vector v2 = p - a;
	if (cross(v1, v2) <= 0) return 0;

	int s=abs(cross(v1, v2));
	i128 l2=dot(v1,v1);
	return l2*r*r <= (i128)s*s;
}

void solve()
{
	int n;
	cin>>n;
	vector<Point> a(n);
	Point p0;
	int r;
	cin>>p0.x>>p0.y>>r;
	for(int i=0;i<n;i++) cin>>a[i].x>>a[i].y;

	int cnt=2;
	int ans=0,cur=0;
	int p=2;
	for(int i=0;i<n;i++) {
		while (p != (i-1+n)%n and check(p0,a[i],a[p],r)) {
			cnt++;
			cur+=S(a[i],a[p],a[(p-1+n)%n]);
			ans=max(ans,cur);
			p++;
			p%=n;
		}

		if (cnt >= 3) cur-=S(a[i],a[(i+1)%n],a[(p-1+n)%n]),cnt--;
		else p++,p%=n;
	}

	cout<<ans<<"\n";
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







