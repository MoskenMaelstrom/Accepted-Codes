// Problem: D - Reachability Query 2
// Contest: AtCoder - AtCoder Beginner Contest 435
// URL: https://atcoder.jp/contests/abc435/tasks/abc435_d
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
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
		adj[v].push_back(u);
	}
	
	vector<bool> vec(n);
	vector<bool> mark(n);
	function<void(int)> dfs=[&](int u) {
		if (vec[u]) return;
		mark[u]=vec[u]=1;
		for(auto v : adj[u]) {
			dfs(v);
		}
		mark[u]=0;
 	};
	
	int q;
	cin>>q;
	while (q--) {
		int opt,u;
		cin>>opt>>u;
		u--;
		if (opt == 1) {
			dfs(u);
		}
		else {
			if (vec[u]) cout<<"Yes\n";
			else cout<<"No\n";
		}
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







