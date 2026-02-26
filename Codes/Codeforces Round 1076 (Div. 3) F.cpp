// Problem: F. Pizza Delivery
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n,x1,y1,x2,y2;
	cin>>n>>x1>>y1>>x2>>y2;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) cin>>a[i][0];
	for(int i=0;i<n;i++) cin>>a[i][1];
	
	ranges::sort(a);
	vector<array<int,2>> vec;
	vec.push_back({y1,y1});
	int cur=0,hi=-inf,lo=inf;
	for(int i=0;i<n;i++) {
		auto [x,y]=a[i];
		if (x != cur and lo != inf) {
			vec.push_back({lo,hi});
			hi=-inf;
			lo=inf;
		}
		cur=x;
		hi=max(hi,y);
		lo=min(lo,y);
	}
	if (lo != inf) vec.push_back({lo,hi});
	vec.push_back({y2,y2});
	
	vector<array<int,2>> dp(vec.size());
	for(int i=1;i<vec.size();i++) {
		dp[i][0]=min(dp[i-1][0]+abs(vec[i][1]-vec[i-1][0]), dp[i-1][1]+abs(vec[i][1]-vec[i-1][1]));
		dp[i][0]+=abs(vec[i][0]-vec[i][1]);
		dp[i][1]=min(dp[i-1][0]+abs(vec[i][0]-vec[i-1][0]), dp[i-1][1]+abs(vec[i][0]-vec[i-1][1]));
		dp[i][1]+=abs(vec[i][0]-vec[i][1]);
	}
	
	cout<<min(dp[vec.size()-1][0],dp[vec.size()-1][1])+x2-x1<<"\n";
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







