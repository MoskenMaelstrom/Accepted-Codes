// Problem: F. Isoball: 2D Version
// Contest: Codeforces - The 2024 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105222/problem/F
// Memory Limit: 256 MB
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
int cmp(double x, double y) {
    if (fabsl(x - y) < eps) return 0;
    return x < y ? -1 : 1;
}

void solve()
{
	int x0,y0,r,vx,vy;
	cin>>x0>>y0>>r>>vx>>vy;
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	double x3=x0-r,y3=y0-r; 
	double x4=x0+r,y4=y0+r;
	double dx=x4-x3,dy=y4-y3;
	
	double nx,ny;
	if (vy != 0 and vy*(y1-y3) >= 0) {
		ny=y1;
		nx=x3+(y1-y3)*((double)vx/vy);
		if (cmp(nx,x1) != -1 and cmp(nx+dx,x2) != 1 and cmp(ny+dy,y2) != 1) {cout<<"Yes\n";return;}
	}
	
	if (vx != 0 and vx*(x1-x3) >= 0) {
		nx=x1;
		ny=y3+(x1-x3)*((double)vy/vx);
		// cout<<nx<<" "<<ny<<endl;
		// cout<<nx+dx<<" "<<ny+dy<<endl;
		// cout<<x2<<" "<<y2<<endl;
		if (cmp(ny,y1) != -1 and cmp(nx+dx,x2) != 1 and cmp(ny+dy,y2) != 1) {cout<<"Yes\n";return;}
	}
	
	if (vy != 0 and vy*(y2-y4) >= 0) {
		ny=y2;
		nx=x4+(y2-y4)*((double)vx/vy);
		if (cmp(nx,x2) != 1 and cmp(nx-dx,x1) != -1 and cmp(ny-dy,y1) != -1) {cout<<"Yes\n";return;}
	}
	
	if (vx != 0 and vx*(x2-x4) >= 0) {
		nx=x2;
		ny=y4+(x2-x4)*((double)vy/vx);
		if (cmp(ny,y2) != 1 and cmp(ny-dy,y1) != -1 and cmp(nx-dx,x1) != -1) {cout<<"Yes\n";return;}
	}
	
	cout<<"No\n";
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







