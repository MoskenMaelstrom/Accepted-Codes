// Problem: H. Fallen Leaves
// Contest: Codeforces - Codeforces Round 1096 (Div. 3)
// URL: https://codeforces.com/contest/2227/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	
	int r=-1;
	for(int i=0;i<n;i++) {
		if (adj[i].size() > 1) {r=i;break;}
	}
	assert(r != -1);
	
	vector<int> fa(n);
	fa[r]=-1;
	auto dfs=[&](auto&& self,int u) -> void {
		for(auto v : adj[u]) {
			if (v == fa[u]) continue;
			fa[v]=u;
			self(self,v);
		}
	};
	dfs(dfs,r);
	
	vector<int> cnt(n);
	for(int i=0;i<n;i++) {
		if (adj[i].size() == 1) cnt[i]=1;
	}
	auto dfs1=[&](auto&& self,int u) -> void {
		for(auto v : adj[u]) {
			if (v == fa[u]) continue;
			self(self,v);
			cnt[u]+=cnt[v];
		}
	};
	dfs1(dfs1,r);
	
	int ans=0;
	for(int i=0;i<n;i++) {
		if (i == r) continue;
		if (cnt[i]&1) ans++;
	}
	
	if (cnt[r]%2 == 0) cout<<ans<<"\n";
	else {
		vector<int> dp(n);
		auto dfs2=[&](auto&& self,int u) -> void {
			int res=0;
			for(auto v : adj[u]) {
				if (v == fa[u]) continue;
				self(self,v);
				res=max(res,dp[v]+(cnt[v]&1 ? 1ll : -1ll));
			}
			dp[u]=res;
		};
		dfs2(dfs2,r);
		cout<<ans-dp[r]<<"\n";
	}
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







