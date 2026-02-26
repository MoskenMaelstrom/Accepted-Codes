#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> mark(n);
	auto dfs=[&](auto self,int u) -> bool {
		mark[u]=1;
		// if (a[u] == 0) return 0;
		if (adj[u].size() == 1 and mark[adj[u][0]]) return 0;
		
		bool ok=0;
		for(auto v : adj[u]) {
			if (mark[v]) continue;
			if (self(self,v) == 0 and a[u] > a[v]) ok=1; 
		}
		return ok;
	};
	
	vector<int> ans;
	for(int i=0;i<n;i++) {
		fill(mark.begin(),mark.end(),0);
		if (dfs(dfs,i)) ans.push_back(i+1);
	}
	ranges::sort(ans);
	for(auto e1 : ans) cout<<e1<<" ";
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









