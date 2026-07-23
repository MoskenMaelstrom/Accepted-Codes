// Problem: Fabulous Tree
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133877/F
// Memory Limit: 1024 MB
// Time Limit: 12000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector adj(n,vector<array<int,2>>(0));
	int W=0;
	for(int i=0;i<n-1;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		W=max(w,W);
	}
	
	vector dp(n,vector<int>(2*W+1));
	vector<int> ans(n,inf);
	auto dfs=[&](auto&& self,int u,int fa) -> void {
		for(auto [v,w] : adj[u]) {
			if (v == fa) continue;
			self(self,v,u);
			for(int i=0;i<=2*W;i++) {
				if (i+w > 2*W) dp[u][i]=min(dp[u][i],dp[v][i-w]+w);
				else if (i < w) dp[u][i]=min(dp[u][i],dp[v][i+w]-w);
				else dp[u][i]=min(dp[u][i],max(dp[v][i+w]-w,dp[v][i-w]+w));
			}
		}
		for(int i=0;i<=2*W;i++) ans[u]=min(ans[u],i-dp[u][i]);
	};
	dfs(dfs,0,-1);
	for(auto e1 : ans) cout<<e1<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







