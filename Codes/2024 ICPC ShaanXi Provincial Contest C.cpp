// Problem: C. Seats
// Contest: Codeforces - 2024 ICPC ShaanXi Provincial Contest
// URL: https://codeforces.com/gym/105257/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector adj(2*n+1,vector<int>(0));
	// vector<int> a(n+1);
	// for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> fa(2*n+1);
	vector<int> deg(2*n+1);
	for(int i=1;i<=n;i++) {
		int u;
		cin>>u;
		adj[u].push_back(i);
		fa[i]=u;
		deg[u]++;
	}
	
	vector<int> vis(2*n+1);
	queue<int> q;
	for(int i=1;i<=n;i++) {
		if (deg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		vis[u]=1;
		if (fa[u] == 0 or fa[u] > n) continue;
		deg[fa[u]]--;
		if (deg[fa[u]] == 0) q.push(fa[u]);
	}
	
	vector<int> vis1(2*n+1);
	for(int i=1;i<=n;i++) if (!vis[i]) vis1[i]=1;
	int sum=n-ranges::count(vis,1);
	// auto dfs1=[&](auto&& self,int u) -> void {
		// if (vis[u]) return;
		// sum++;
		// vis[u]=1;
		// vis1[u]=1;
		// self(self,fa[u]);	
	// };
	// for(int i=1;i<=n;i++) {
		// if (vis[i] == 0) {
			// dfs1(dfs1,i);
		// }
	// }
	// cout<<sum<<"\n";
	
	vector<int> vec;
	for(int i=1;i<=n;i++) {
		if (vis1[i]) continue;
		if (fa[i] == 0 or fa[i] > n) vec.push_back(i);
		else {
			int p=fa[i];
			if (p > n) continue;
			while (fa[p] != 0 and fa[p] <= n and !vis1[p]) {
				vis1[p]=1;
				p=fa[p];
			}
			if (p > n or vis1[p]) continue;
			vec.push_back(p);
		}
	}
	
	vector<int> ans(n+1);
	auto dfs2=[&](auto&& self,int id,int u,int deep) -> void {
		ans[id]=max(deep,ans[id]);
		for(auto v : adj[u]) {
			self(self,id,v,deep+1);
		}
	};
	for(auto u : vec) dfs2(dfs2,u,u,1);
	
	vector<bool> mark(2*n+1);
	for(int i=n+1;i<=2*n;i++) {
		int maxn=0;
		for(auto u : adj[i]) {
			mark[u]=1;
			maxn=max(maxn,ans[u]);
		}
		sum+=maxn;
	}
	for(auto u : vec) {
		if (mark[u]) continue;
		sum+=vec[u];
	}
	cout<<sum;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _=1;
	// cin>>_;
	while(_--) solve();
}