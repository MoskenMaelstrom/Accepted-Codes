// Problem: P1060 [NOIP 2006 普及组] 开心的金明
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1060
// Memory Limit: 64 MB
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
	int n,m;
	cin>>n>>m;
	vector<int> cost(m),val(m);
	vector<int> dp(n+1);
	for(int i=0;i<m;i++) {cin>>cost[i]>>val[i];val[i]*=cost[i];}
	
	for(int i=0;i<m;i++) {
		for(int j=n;j>=cost[i];j--) {
			dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
		}
	}
	cout<<dp[n];
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









