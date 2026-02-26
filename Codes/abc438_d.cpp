// Problem: D - Tail of Snake
// Contest: AtCoder - AtCoder Beginner Contest 438
// URL: https://atcoder.jp/contests/abc438/tasks/abc438_d
// Memory Limit: 1024 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++) cin>>c[i];
	
	vector<array<int,3>> dp(n,{-inf,-inf,-inf});
	dp[0][0]=a[0];
	for(int i=1;i<n;i++) {
		dp[i][0]=dp[i-1][0]+a[i];
		dp[i][1]=max(dp[i-1][0]+b[i],dp[i-1][1]+b[i]);
		dp[i][2]=max(dp[i-1][1]+c[i],dp[i-1][2]+c[i]);
	}
	cout<<dp[n-1][2];
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







