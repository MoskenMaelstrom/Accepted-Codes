// Problem: G. Download Time Monitor
// Contest: Codeforces - 2024 Jiangsu Collegiate Programming Contest
// URL: https://codeforces.com/gym/105161/problem/G
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: G. Download Time Monitor
// Contest: Codeforces - 2024 Jiangsu Collegiate Programming Contest
// URL: https://codeforces.com/gym/105161/problem/G
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int _B,_t1,_a1,_t2,_a2;
	cin>>_B>>_t1>>_a1>>_t2>>_a2;
	double B=_B;
	double t1=_t1;
	double a1=_a1;
	double t2=_t2;
	double a2=_a2;
	
	double ans1=0,ans2=0;
	double T0=t2-t1;
	if (a1-T0*B <= 0) ans1=a1/B,a1=0;
	else ans1+=T0,a1-=T0*B;
	
	double d1=a1/(B/2);
	double d2=a2/(B/2);
	if (d1 > d2) {
		ans1+=d2;
		ans2+=d2;
		a1-=a2;
		a2=0;
		ans1+=a1/B;
	}
	else {
		ans1+=d1;
		ans2+=d1;
		a2-=a1;
		a1=0;
		ans2+=a2/B;
	}
	cout<<fixed<<setprecision(9)<<ans1<<" "<<ans2<<"\n";
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







