// Problem: E - Laser Takahashi
// Contest: AtCoder - JPRS Programming Contest 2026#1 (AtCoder Beginner Contest 442)
// URL: https://atcoder.jp/contests/abc442/tasks/abc442_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

struct Point {
    int x, y;
};
typedef Point Vector;

int dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

int cross(Vector a, Vector b) {
    return a.x * b.y - b.x * a.y;
}

bool p_cmp(const Vector& a, const Vector& b) {
    int ha = (a.y > 0 or a.y == 0 and a.x > 0);
    int hb = (b.y > 0 or b.y == 0 and b.x > 0);
    if (ha != hb) return ha < hb;
    int c = cross(a, b);
    return c > 0;
}

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<Point> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i].x>>vec[i].y;
	auto p=vec;
	ranges::sort(p,p_cmp);
	while (q--) {
		int A,B;
		cin>>A>>B;
		A--,B--;
		int l=ranges::lower_bound(p,vec[B],p_cmp)-p.begin();
		int r=ranges::upper_bound(p,vec[A],p_cmp)-p.begin();
		if (l >= r) r+=n;
		cout<<r-l<<"\n";
	}
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







