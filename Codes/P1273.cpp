// Problem: P1273 有线电视网
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1273
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector adj(n,vector<int>(0));
	vector<int> cost(n);
	for(int i=0;i<n-m;i++) {
		int k;
		cin>>k;
		while (k--) {
			int v,w;
			cin>>v>>w;
			v--;
			adj[i].push_back(v);
			cost[v]=w;
		} 
	}
	
	for(int i=n-m;i<n;i++) {
		int w;
		cin>>w;
		cost[i]-=w;
	}
	
	vector<bool> mark(n);
	vector<int> dfn(n);
	vector<int> siz(n,1);
	int order=0;
	auto dfs=[&](auto self,int u) -> int {
		mark[u]=1;
		dfn[order++]=u;
		for(auto v : adj[u]) {
			if (mark[v]) continue;
			siz[u]+=self(self,v);
		}
		return siz[u];
	};
	dfs(dfs,0);
	
	vector dp(n+1,vector<int>(m+1,inf));
	for(int i=0;i<=n;i++) dp[i][0]=0;
	for(int i=n-1;i>=0;i--) {
		int u=dfn[i];
		for(int j=1;j<=m;j++) {
			if (u >= n-m) {
				dp[i][j]=min(dp[i+1][j-1]+cost[u],dp[i+1][j]);
			}
			else {
				dp[i][j]=min(dp[i+1][j]+cost[u],dp[i+siz[u]][j]);
			}
		}
	}
	
	int ans=0;
	for(int j=1;j<=m;j++) {
		if (dp[0][j] <= 0) ans=j;
	}
	cout<<ans;
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









