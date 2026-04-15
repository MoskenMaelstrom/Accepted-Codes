// Problem: E. Tree Painting
// Contest: Codeforces - Educational Codeforces Round 67 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1187/E
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
	vector<int> siz(n,1);
	vector<int> sum(n);
	auto dfs1=[&](auto&& self,int u,int fa) -> void {
		for(auto v : adj[u]) {
			if (v == fa) continue;
			self(self,v,u);
			siz[u]+=siz[v];
			sum[u]+=sum[v];
		}
		sum[u]+=siz[u];
	};
	dfs1(dfs1,0,-1);
	// for(auto e1 : sum) cout<<e1<<" ";
	
	int ans=sum[0];
	auto dfs2=[&](auto&& self,int u,int fa) -> void {
		sum[u]=sum[fa]+n-2*siz[u];
		ans=max(ans,sum[u]);
		for(auto v : adj[u]) {
			if (v == fa) continue;
			self(self,v,u);
		}
	};
	for(auto v : adj[0]) {
		dfs2(dfs2,v,0);
	}
	cout<<ans;
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







