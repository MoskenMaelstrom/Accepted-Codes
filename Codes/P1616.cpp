// Problem: P1616 疯狂的采药
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1616
// Memory Limit: 128 MB
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int m,n;
	cin>>m>>n;
	vector<int> cost(n+1),val(n+1);
	for(int i=1;i<=n;i++) {
		cin>>cost[i]>>val[i];
	}
	
	vector<int> dp(m+1);
	
	for(int i=1;i<=n;i++) {
		for(int j=cost[i];j<=m;j++) {
			dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
		}
	}
	cout<<dp[m];
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









