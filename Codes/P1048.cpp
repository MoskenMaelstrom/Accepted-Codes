// Problem: P1048 [NOIP 2005 普及组] 采药
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1048
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
	int T,n;
	cin>>T>>n;
	vector<int> cost(n),val(n);
	for(int i=0;i<n;i++) cin>>cost[i]>>val[i];
	
	auto bag=[&]() -> vector<int> {
		vector<int> dp(T+1);
		for(int i=0;i<n;i++) {
			for(int j=T;j>=cost[i];j--) {
				dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
			}
		}
		return dp;
	};
	
	vector<int> dp=bag();
	cout<<dp[T];
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









