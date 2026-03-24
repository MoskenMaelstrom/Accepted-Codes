// Problem: J. RGB 树
// Contest: Codeforces - 第十三届重庆市大学生程序设计竞赛
// URL: https://codeforces.com/gym/105887/problem/J
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector adj(n,vector<int>(0));
	vector<int> deg(n);
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	vector<int> vis(n);
	auto dfs1=[&](auto&& self,int u,int c) -> void {
		for(auto v : adj[u]) {
			if (vis[v]) continue;
			if (s[v] == c) vis[v]=2,self(self,v,c);
		}
	};
	
	int ans=n;
	for(int i=0;i<n;i++) {
		if (deg[i] == 1) {
			ans--;
			if (!vis[i]) dfs1(dfs1,i,s[i]);
			vis[i]=1; 
		}
	}
	
	int cnt=0;
	auto dfs2=[&](auto&& self,int u,int fa,int c) -> bool {
		bool f=0;
		for(auto v : adj[u]) {
			if (v == fa) continue;
			f|=self(self,v,u,c);
		}
		if (f and s[u] == c) vis[u]=1;
		return f or s[u] != c;
	};
	
	for(int i=0;i<n;i++) {
		if (s[i] == 'R') {
			for(auto v : adj[i]) dfs2(dfs2,v,i,'G');
			for(auto v : adj[i]) dfs2(dfs2,v,i,'B');
			break;
		}
	}
	for(int i=0;i<n;i++) {
		if (s[i] == 'G') {
			for(auto v : adj[i]) dfs2(dfs2,v,i,'R');
			for(auto v : adj[i]) dfs2(dfs2,v,i,'B');
			break;
		}
	}
	for(int i=0;i<n;i++) {
		if (s[i] == 'B') {
			for(auto v : adj[i]) dfs2(dfs2,v,i,'R');
			for(auto v : adj[i]) dfs2(dfs2,v,i,'G');
			break;
		}
	}
	
	cout<<ans-ranges::count(vis,2);
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







