// Problem: P2014 [CTSC1997] 选课
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2014
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

void solve()
{
	int n,m;
	cin>>n>>m;
	m++;
	vector<int> score(n+1);
	vector adj(n+1,vector<int>(0));
	for(int i=1;i<=n;i++) {
		int v,w;
		cin>>v>>w;
		adj[v].push_back(i);
		score[i]=w;
	}
	
	vector<int> dfn(n+1,-1);
	vector<bool> mark(n+1,0);
	vector<int> siz(n+1,1);
	int order=0;
	auto dfs=[&](auto self,int u) -> int {
		dfn[order++]=u;
		mark[u]=1;
		for(auto v : adj[u]) {
			if (mark[v]) continue;
			siz[u]+=self(self,v);
		}
		return siz[u];
	};
	dfs(dfs,0);
	
	vector dp(n+1,vector<int>(m+1));
	for(int i=n;i>=0;i--) {
		int u=dfn[i];
		for(int j=1;j<=m;j++) {
			if (i+1 > n) dp[i][j]=score[u];
			else if (i+siz[u] > n) dp[i][j]=dp[i+1][j-1]+score[u];
			else dp[i][j]=max(dp[i+1][j-1]+score[u],dp[i+siz[u]][j]);
		}
	}
	cout<<dp[0][m];
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









