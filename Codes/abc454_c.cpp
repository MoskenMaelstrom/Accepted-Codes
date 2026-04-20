// Problem: C - Straw Millionaire
// Contest: AtCoder - Keysight Technologies Programming Contest（AtCoder Beginner Contest 454）
// URL: https://atcoder.jp/contests/abc454/tasks/abc454_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector adj(n,vector<int>(0));
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
	}
	vector<bool> vis(n);
	auto dfs=[&](auto&& self,int u) -> void {
		vis[u]=1;
		for(auto v : adj[u]) {
			if (vis[v]) continue;
			self(self,v);
		}
	};
	dfs(dfs,0);
	cout<<ranges::count(vis,1);
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







