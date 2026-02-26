// Problem: H. Remove the Grail Tree
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/H
// Memory Limit: 256 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		a[i]&=1;
	}
	vector adj(n,vector<int>());
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	auto vec=a;
	for(int i=0;i<n;i++) {
		for(int u : adj[i]) vec[i]^=a[u];
	}
	
	vector<int> ans;
	vector<bool> mark(n);
	auto del=[&](int u) {
		mark[u]=1;
		ans.push_back(u);
		for(auto v : adj[u]) vec[v]^=a[u];
	};
	
	vector<int> ord;
	function<void(int,int)> dfs=[&](int u,int fa) -> void {
		ord.push_back(u);
		for(auto v : adj[u]) {
			if (a[u] == 0 and !mark[u] and vec[u]) del(u);
			if (v != fa) dfs(v,u);
		}
		if (!mark[u] and vec[u]) del(u);
	};
	dfs(0,0);
	for(auto u : ord) {
		if (!mark[u] and vec[u]) del(u);
	}
	
	if (ans.size() == n) {
		cout<<"YES\n";
		for(auto e1 : ans) cout<<e1+1<<" ";
		cout<<"\n";
	}
	else cout<<"NO\n";
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







