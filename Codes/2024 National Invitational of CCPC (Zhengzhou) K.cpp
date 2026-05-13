// Problem: K. 树上问题
// Contest: Codeforces - 2024 National Invitational of CCPC (Zhengzhou), 2024 CCPC Henan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105158/problem/K
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
	if (n == 1) {cout<<1<<"\n";return;}
	
	vector<int> cnt(n);
	auto dfs0=[&](auto&& self,int u,int fa) -> void {
		for(auto v : adj[u]) {
			if (v == fa) continue;
			if (a[v]*2 >= a[u]) cnt[0]++;
			self(self,v,u);
		}
	};
	dfs0(dfs0,0,-1);
	
	auto dfs1=[&](auto&& self,int u,int fa) -> void {
		for(auto v : adj[u]) {
			if (v == fa) continue;
			cnt[v]=cnt[u]-(a[v]*2 >= a[u] ? 1 : 0)+(a[u]*2 >= a[v] ? 1 : 0);
			self(self,v,u);
		}
	};
	dfs1(dfs1,0,-1);
	
	cout<<ranges::count(cnt,n-1)<<"\n";
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







