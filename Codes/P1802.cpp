// Problem: P1802 5 倍经验日
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1802
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n,x;
	cin>>n>>x;
	vector<int> lose(n),win(n),cost(n);
	for(int i=0;i<n;i++) {
		cin>>lose[i]>>win[i]>>cost[i];
	}
	
	vector<int> dp(x+1);
	for(int i=0;i<n;i++) {
		for(int j=x;j>=0;j--) {
			if (j >= cost[i]) dp[j]=max(dp[j]+lose[i],dp[j-cost[i]]+win[i]);
			else dp[j]=dp[j]+lose[i];
		}
	}
	cout<<dp[x]*5;
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









