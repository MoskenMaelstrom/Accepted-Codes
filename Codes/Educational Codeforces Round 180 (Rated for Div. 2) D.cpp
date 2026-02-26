// Problem: D. Reachability and Tree
// Contest: Codeforces - Educational Codeforces Round 180 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2112/D
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
	int n;
	cin>>n;
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	
	int p=-1;
	for(int i=0;i<n;i++) {
		if (adj[i].size() == 2) {p=i;break;}
	}
	
	if (p == -1) {cout<<"NO\n";return;}
	
	vector<array<int,2>> ans;
	int v1=adj[p][0];
	int v2=adj[p][1];
	
	vector<bool> mark(n);
	mark[p]=1;
	ans.push_back({v1,p});
	ans.push_back({p,v2});
	
	//dir=0入, dir=1出
	auto dfs=[&](this auto &&self,int u,bool dir) -> void {
		mark[u]=1;
		for(auto v : adj[u]) {
			if (mark[v]) continue;
			if (dir == 0) {
				ans.push_back({v,u});
				self(v,1);
			}
			else {
				ans.push_back({u,v});
				self(v,0);
			}
		}
	};
	
	dfs(v1,1);
	dfs(v2,0);
	cout<<"YES\n";
	for(auto [u,v] : ans) cout<<u+1<<" "<<v+1<<"\n";
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









