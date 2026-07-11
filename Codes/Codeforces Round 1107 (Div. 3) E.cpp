// Problem: E. Fair and Square
// Contest: Codeforces - Codeforces Round 1107 (Div. 3)
// URL: https://codeforces.com/contest/2241/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	vector<int> siz(n,1);
	auto dfs=[&](auto&& self,int u,int fa) -> void {
		for(auto v : adj[u]) {
			if (v == fa) continue;
			self(self,v,u);
			siz[u]+=siz[v];
		}
	};
	dfs(dfs,0,-1);
	
	int ans=0;
	for(int i=0;i<n;i++) {
		int num=sqrt(a[i]);
		if (num*num != a[i]) continue;
		// if (siz[i] != 1 and siz[i] != n) {
			ans+=(n-1)*(n-2)/2;
			ans-=(n-siz[i])*(n-siz[i]-1)/2;
			for(auto v : adj[i]) {
				if (siz[v] > siz[i]) continue;
				ans-=siz[v]*(siz[v]-1)/2;
			}
			// cout<<ans<<"!!\n";
			
			ans+=(n-1)*(n-2)*(n-3)/6;
			if (n-siz[i] >= 3) ans-=(n-siz[i])*(n-siz[i]-1)*(n-siz[i]-2)/6;
			if (n-siz[i] >= 2) ans-=(n-siz[i])*(n-siz[i]-1)/2*(siz[i]-1);
			for(auto v : adj[i]) {
				if (siz[v] > siz[i]) continue;
				if (siz[v] >= 3) ans-=siz[v]*(siz[v]-1)*(siz[v]-2)/6;
				if (siz[v] >= 2) ans-=siz[v]*(siz[v]-1)/2*(n-siz[v]-1);
			}
			// cout<<ans<<"!!!\n";
		// }
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







