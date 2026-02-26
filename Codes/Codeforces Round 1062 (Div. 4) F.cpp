// Problem: F. Tree, TREE!!!
// Contest: Codeforces - Codeforces Round 1062 (Div. 4)
// URL: https://codeforces.com/contest/2167/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	int n,k;
	cin>>n>>k;
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> siz(n);
	vector<bool> mark(n);
	auto dfs=[&](this auto&& self,int u,int ba) -> void {
		siz[u]=1;
		for(auto v : adj[u]) {
			if (v != ba) {
				self(v,u);
				siz[u]+=siz[v];
			}
		}
	};
	dfs(0,-1);
	
	int ans=0;
	auto work=[&](this auto&& self,int u,int ba) -> void {
		ans++;
		if (siz[u] >= k) ans+=n-siz[u];
		for(auto v : adj[u]) {
			if (v != ba) {
				self(v,u);
				if (n-siz[v] >= k) ans+=siz[v];
			}
		}
	};
	work(0,-1);
	cout<<ans<<"\n";
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









