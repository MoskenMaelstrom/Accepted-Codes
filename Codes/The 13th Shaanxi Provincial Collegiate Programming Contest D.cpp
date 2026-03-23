// Problem: D. Stock
// Contest: Codeforces - The 13th Shaanxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105891/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	double x;
	cin>>n>>x;
	vector<double> a,b;
	for(int i=0;i<n;i++) {
		char c;
		double num;
		cin>>c>>num;
		if (c == '+') a.push_back(num);
		else b.push_back(num);
	}
	ranges::sort(a,greater<double>());
	ranges::sort(b,greater<double>());
	
	int n1=a.size();
	int n2=b.size();
	double ans=0;
	auto dfs=[&](auto&& self,int c1,int c2,double cur,double sum) -> void {
		ans=max(ans,sum);
		if (c1 < n1) self(self,c1+1,c2,cur+a[c1],sum+cur+a[c1]);
		if (c2 < n2) self(self,c1,c2+1,cur*b[c2],sum+cur*b[c2]);
	};
	dfs(dfs,0,0,x,0);
	cout<<fixed<<setprecision(10)<<ans/n;
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







