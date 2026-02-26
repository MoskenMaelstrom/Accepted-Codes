// Problem: P1352 没有上司的舞会
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1352
// Memory Limit: 128 MB
// Time Limit: 1000 ms
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
	vector<int> a(n),fa(n,-1);
	vector adj(n,vector<int>(0));
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[v].push_back(u);
		fa[u]=v;
	}
	int p;
	for(int i=0;i<n;i++) if (fa[i] == -1) p=i;
	
	map<array<int,2>,int> mp;
	auto dfs=[&](auto self,int u,int f) -> int {
		if (mp.count({u,f})) return mp[{u,f}];
		if (f == 0) {
			int res=0;
			for(auto v : adj[u]) {
				res=max(res+self(self,v,0),res+self(self,v,1));
			}
			return mp[{u,f}]=res;
		}
		else {
			int res=a[u];
			for(auto v : adj[u]) {
				res+=self(self,v,0);
			}
			return mp[{u,f}]=res;
		}
	};
	
	cout<<max(dfs(dfs,p,0),dfs(dfs,p,1));
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









