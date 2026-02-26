// Problem: P1359 租用游艇
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1359
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector a(n+1,vector<int>(n+1));
	for(int i=1;i<=n-1;i++) {
		for(int j=i+1;j<=n;j++) {
			cin>>a[i][j];//i到j
		}
	}
	vector<int> dp(n+1);
	dp[n-1]=a[n-1][n];
	for(int i=n-2;i>=0;i--) {
		dp[i]=a[i][n];
		for(int j=i+1;j<=n-1;j++) dp[i]=min(dp[i],a[i][j]+dp[j]);
	}
	// for(auto e1 : dp) cout<<e1<<" ";
	cout<<dp[1];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









