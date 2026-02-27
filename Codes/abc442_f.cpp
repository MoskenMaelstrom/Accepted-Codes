// Problem: F - Diagonal Separation 2
// Contest: AtCoder - JPRS Programming Contest 2026#1 (AtCoder Beginner Contest 442)
// URL: https://atcoder.jp/contests/abc442/tasks/abc442_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector a(n+1,vector<char>(n+1));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	
	vector dp(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++) {
		vector<int> c1(n+1);
		for(int j=1;j<=n;j++) {
			if (a[i][j] == '#') c1[j]++;
			c1[j]+=c1[j-1];
		}
		for(int j=0;j<=n;j++) {
			dp[i][j]=dp[i-1][j];
			dp[i][j]+=c1[j]+(n-j)-(c1[n]-c1[j]);
		}
		for(int j=n-1;j>=0;j--) {
			dp[i][j]=min(dp[i][j+1],dp[i][j]);
		}
	}
	cout<<dp[n][0];
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







