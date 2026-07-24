// Problem: Turn-by-Turn Navigation
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133878/K
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int sign(int x) {
    if (x == 0) return 0;
    return x < 0 ? -1 : 1;
}

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

int dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

int cross(Vector a, Vector b) {
    return a.x * b.y - b.x * a.y;
}

void solve()
{
	int n;
	cin>>n;
	vector<Point> vec(n);
	for(int i=0;i<n;i++) {
		cin>>vec[i].x>>vec[i].y;
	}
	
	for(int i=1;i<n-1;i++) {
		Vector v1=vec[i]-vec[i-1];
		Vector v2=vec[i+1]-vec[i];
		int res=cross(v1,v2);
		if (res == 0) cout<<"STRAIGHT ";
		else if (res > 0) cout<<"LEFT ";
		else cout<<"RIGHT ";
	}
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







