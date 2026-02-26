// Problem: E - Remembering the Days
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/E
// Memory Limit: 1024 MB
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
	vector adj(n,vector<array<int,2>>(0));
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	int ans=0;
	vector<bool> vis(n);
	auto dfs=[&](auto self,int p,int len) -> void {
		vis[p]=1;
		ans=max(ans,len);
		for(auto [v,w] : adj[p]) {
			if (vis[v] == 1) continue;
			self(self,v,len+w);
		}
		vis[p]=0;
	};
		
	for(int i=0;i<n;i++) {
		dfs(dfs,i,0);
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









