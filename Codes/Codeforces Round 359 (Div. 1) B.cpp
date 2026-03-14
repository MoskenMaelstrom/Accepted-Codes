// Problem: B. Kay and Snowflake
// Contest: Codeforces - Codeforces Round 359 (Div. 1)
// URL: https://codeforces.com/problemset/problem/685/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> fa(n);
	vector adj(n,vector<int>(0));
	for(int i=1;i<=n-1;i++) {
		cin>>fa[i];
		fa[i]--;
		adj[fa[i]].push_back(i);
	}
	
	vector<int> siz(n,1);
	vector<int> g(n);
	function<void(int)> dfs=[&](int u) {
		g[u]=u;
		for(int v : adj[u]) {
			dfs(v);
			siz[u]+=siz[v];
		}
		
		for(int v : adj[u]) {
			if (siz[v]*2 < siz[u]) continue;
			int x=g[v];
			while (siz[x]*2 < siz[u]) x=fa[x];
			g[u]=x;
		}
	};
	dfs(0);
	
	while (q--) {
		int u;
		cin>>u;
		u--;
		cout<<g[u]+1<<"\n";
	}
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







