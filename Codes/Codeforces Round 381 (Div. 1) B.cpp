// Problem: B. Alyona and a tree
// Contest: Codeforces - Codeforces Round 381 (Div. 1)
// URL: https://codeforces.com/problemset/problem/739/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector adj(n+1,vector<array<int,2>>(0));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) {
		int u,w;
		cin>>u>>w;
		adj[u].push_back({i,w});
	}
	
	vector<int> vec(n+1),deep(n+1);
	vector<array<int,2>> p(1,{-inf,0});
	function<void(int)> dfs=[&](int u) {
		vec[u]++;
		auto it=--ranges::lower_bound(p,array<int,2>{deep[u]-a[u],-1});
		vec[(*it)[1]]--;
		p.push_back({deep[u],u});
		for(auto [v,w] : adj[u]) {
			deep[v]=deep[u]+w;
			dfs(v);
			vec[u]+=vec[v];
		}
		p.pop_back();
	};
	dfs(1);
	for(int i=1;i<=n;i++) cout<<vec[i]-1<<" ";
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







