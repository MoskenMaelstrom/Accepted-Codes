// Problem: Tree.zip
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133878/J
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
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
	int n,q;
	cin>>n>>q;
	vector adj(n,vector<int>(0));
	for(int i=1;i<n;i++) {
		int u;
		cin>>u;
		u--;
		adj[u].push_back(i);
	}
	
	vector<int> d(n);
	vector vec(n,vector<int>(0));
	auto dfs=[&](auto&& self,int u) -> void {
		for(auto v : adj[u]) {
			d[v]=d[u]+1;
			self(self,v);
		}
	};
	dfs(dfs,0);
	for(int i=0;i<n;i++) vec[d[i]].push_back(i);
	
	vector<set<array<int,2>>> ys(n);
	for(int i=0;i<q;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		ys[u].insert({d[v],v});
	}
	
	vector<int> fa(n);
	for(int i=n-1;i>=0;i--) {
		if (vec[i].empty()) continue;
		for(auto u : vec[i]) {
			while (!ys[u].empty() and (*--ys[u].end())[0] >= d[u]) ys[u].erase(--ys[u].end());
			
			if (ys[u].empty()) fa[u]=0;
			else {
				auto it=--ys[u].end();
				fa[u]=(*it)[1];
				ys[u].erase(it);
				for(auto v : ys[u]) ys[fa[u]].insert(v);
			}
		}
	}
	
	vector<int> ans(n);
	// for(int i=0;i<n;i++) {
		// if (vec[i].empty()) continue;
		// for(auto u : vec[i]) {
			// if (ys[u].empty()) ans[u]=1;
			// else {
				// int mx=-1,fa=-1;
				// for(auto v : ys[u]) {
					// if (mx < ans[v]) mx=ans[v],fa=v;
				// }
				// ans[u]=mx+1;
			// }
		// }
	// }
	
	for(int i=0;i<n;i++) {
		if (vec[i].empty()) continue;
		for(auto u : vec[i]) {
			if (u == 0) continue;
			ans[u]=ans[fa[u]]+1;
		}
	}
	cout<<accumulate(ans.begin(),ans.end(),0ll);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







