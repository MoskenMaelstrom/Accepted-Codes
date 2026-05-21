// Problem: M. Almost Convex
// Contest: Codeforces - The 2023 ICPC Asia Jinan Regional Contest (The 2nd Universal Cup. Stage 17: Jinan)
// URL: https://codeforces.com/gym/104901/problem/M
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
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

// ========================================================================

double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
    return a.x * b.y - b.x * a.y;
}

// 法向量
Vector normal(Vector a) { 
    return Vector(-a.y, a.x);
}

// 求向量的极角
double p_angle(Vector a) {
    return atan2(a.y, a.x);
}

// 极角排序
bool p_cmp(const Vector& a, const Vector& b) {
    int ha = (a.y > 0 or a.y == 0 and a.x > 0);
    int hb = (b.y > 0 or b.y == 0 and b.x > 0);
    if (ha != hb) return ha < hb;
    int c = cross(a, b);
    return c > 0;
}

// 获取向量的模长
double get_length(Vector a) {
    return hypot(a.x, a.y); 
}

// 将向量单位化
Vector unit(Vector a) {
    double l = get_length(a);
    if (sign(l) == 0) return a; // 防止除以 0 的情况
    return a / l;
}

// 计算两个非零向量的夹角
// 返回值：弧度制，范围 [0, PI]
double get_angle(Vector a, Vector b) {
    return fabs(atan2(cross(a, b), dot(a, b))); 
}

// 向量 a 逆时针旋转 angle 角度 (弧度制)
Vector rotate(Vector a, double angle) {
    double c = cos(angle), s = sin(angle);
    return Vector(a.x * c - a.y * s, a.x * s + a.y * c);
}

// 计算点 a, b, c 构成的平行四边形有向面积 (以 a 为顶点)
double area(Point a, Point b, Point c) {
    return cross(b - a, c - a);
}

vector<Point> andrew(vector<Point>& a) {
    sort(a.begin(), a.end());
    vector<Point> l, h;
    for(const auto& p : a) {
        // sign <= 0 表示 p 在前进方向的右侧或共线，维护下凸壳（左转）
        while (l.size() > 1 && sign(area(l[l.size() - 2], l.back(), p)) <= 0) {
            l.pop_back();
        }
        // sign >= 0 表示 p 在前进方向的左侧或共线，维护上凸壳（右转）
        while (h.size() > 1 && sign(area(h[h.size() - 2], h.back(), p)) >= 0) {
            h.pop_back();
        }
        l.push_back(p);
        h.push_back(p);
    }
    
    reverse(h.begin(), h.end());
    h.insert(h.end(), l.begin() + 1, l.end() - 1); //完整凸包
    return h;
}

void solve()
{
	int n;
	cin>>n;
	vector<Point> a(n);
	for(int i=0;i<n;i++) cin>>a[i].x>>a[i].y;
	auto b=andrew(a);
	// for(auto [x,y] : b) cout<<x<<" "<<y<<"\n";
	int m=b.size();
	set<array<int,2>> st;
	for(auto [x,y] : b) st.insert({x,y});
	vector<tuple<double,Point>> vec;
	for(auto [x,y] : a) {
		if (st.find({x,y}) == st.end()) vec.push_back({0,{x,y}});
	}
	
	int ans=1;
	for(int i=0;i<b.size();i++) {
		Point p1=b[i];
		Point p2=b[(i+1)%m];
		for(auto &[ang,p] : vec) {
			ang=get_angle(p2-p1,p-p1);
		}
		sort(vec.begin(),vec.end());
		
		double mint=1e9;
		for(auto [ang,p] : vec) {
			double t=get_angle(p1-p2,p-p2);
			if (t < mint) {
				ans++;
				mint=min(mint,t);
			}
		}
	}
	
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







