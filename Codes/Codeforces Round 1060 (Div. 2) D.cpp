// Problem: D. Catshock
// Contest: Codeforces - Codeforces Round 1060 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2154/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<bool> mark(n);
	queue<array<int,2>> q;
	q.push({0,0});
	vector<vector<int>> vec;
	while (!q.empty()) {
		auto [u,c]=q.front();
		q.pop();
		
		if (vec.size() == c) vec.push_back({});
		mark[u]=1;
		vec[c].push_back(u);
		for(auto v : adj[u]) {
			if (mark[v]) continue;
			q.push({v,c+1});
		}
	}
	
	vector<int> ok(n);
	ok[n-1]=1;
	function<bool(int,int)> dfs=[&](int u,int fa) -> bool {
		if (u == n-1) return 1;
		bool res=0;
		for(auto v : adj[u]) {
			if (v == fa) continue;
			if (dfs(v,u)) res=1;
		}
		return ok[u]=res;
	};
	dfs(0,0);
	
	vector<array<int,2>> ans;
	vector<int> ord;
	int f=0;
	int flag=0;
	for(int i=vec.size()-1;i>=0;i--) {
		for(auto u : vec[i]) {
			if (ok[u]) {ord.push_back(u);continue;}
			while (flag or f%2 == i%2) flag=0,f++,ans.push_back({1,0});
			ans.push_back({2,u}),flag=1;
		}
	}
	
	ranges::reverse(ord);
	for(int i=0;i<ord.size()-1;i++) {
		while (flag or f%2 == i%2) flag=0,f++,ans.push_back({1,0});
		ans.push_back({2,ord[i]});
	}
	
	cout<<ans.size()<<"\n";
	for(auto [opt,u] : ans) {
		if (opt == 1) cout<<1<<"\n";
		else cout<<2<<" "<<u+1<<"\n";
	}
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







