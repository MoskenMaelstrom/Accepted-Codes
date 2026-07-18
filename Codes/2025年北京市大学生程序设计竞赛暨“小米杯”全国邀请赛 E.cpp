// Problem: E. 布置WAP
// Contest: Codeforces - 2025年北京市大学生程序设计竞赛暨“小米杯”全国邀请赛
// URL: https://codeforces.com/gym/105851/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const double eps=1e-7;
void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i][0]>>vec[i][1];
	int a,b,c;
	cin>>a>>b>>c;
	
	auto calc=[&](double t) -> double {
		double x,y;
		if (a == 0) {
			y=-1.0*c/b;
			x=t;
		}
		else if (b == 0) {
			x=-1.0*c/a;
			y=t;
		}
		else {
			x=t;
			y=(-c-a*t)/b;
		}
		double res=0;
		for(auto [x1,y1] : vec) res=max(res,sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)));
		return res;
	};
	
	double lo=-1e5,hi=1e5,res=-1; 
    while (hi-lo > eps) {
        double m1=lo+(hi-lo)/3;
        double m2=hi-(hi-lo)/3;
        if (calc(m1) < calc(m2)) hi=m2;
        else lo=m1;
    }
    cout<<fixed<<setprecision(10)<<calc(lo)<<"\n";
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







