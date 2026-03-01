// Problem: B. Area of the Devil
// Contest: Codeforces - 2024 Jiangsu Collegiate Programming Contest
// URL: https://codeforces.com/gym/105161/problem/B
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

int r;
const double pi=acos(-1);
double calc(int x,int y,int z) {
	if (x < 0) x+=360;
	if (y < 0) y+=360;
	if (z < 0) z+=360;
	
	double ax=x*pi/180,ay=y*pi/180,az=z*pi/180;
	double ans=r*r*ay/2;
	double S=r*r*sin(ay)/2;
	ans-=S;
	
	double d=2*r*sin(ay/2);
	double S2=d/sin(pi-ax/2-az/2)*sin(az/2)*sin(ax/2)*d/2;
	ans+=S2;
	return ans;
}

void solve()
{
	cin>>r;
	double ans=r*r*pi;
	vector<int> a(5),b(5);
	for(int i=0;i<5;i++) cin>>a[i];
	for(int i=0;i<5;i++) cin>>b[i];
	for(int i=0;i<5;i++) {
		ans-=calc(b[(i+1)%5]-b[i],a[(i+2)%5]-b[(i+1)%5],a[(i+3)%5]-a[(i+2)%5]);
	}
	cout<<fixed<<setprecision(9)<<ans<<"\n";
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







