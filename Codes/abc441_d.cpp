// Problem: D - Paid Walk
// Contest: AtCoder - AtCoder Beginner Contest 441 (Promotion of Engineer Guild Fes)
// URL: https://atcoder.jp/contests/abc441/tasks/abc441_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,m,l,s,t;
	cin>>n>>m>>l>>s>>t;
	vector adj(n,vector<array<int,2>>(0));
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].push_back({v,w});
	}
	
	vector<bool> ans(n);
	function<void(int,int,int)> dfs=[&](int u,int step,int cur) {
		if (cur >= s and cur <= t and step == 0) ans[u]=1;
		if (step == 0) return;
		for(auto [v,w] : adj[u]) {
			dfs(v,step-1,cur+w);
		}
	};
	dfs(0,l,0);
	for(int i=0;i<n;i++) {
		if (ans[i]) cout<<i+1<<" ";
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







