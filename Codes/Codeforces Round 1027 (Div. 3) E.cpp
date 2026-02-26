// Problem: E. Kirei Attacks the Estate
// Contest: Codeforces - Codeforces Round 1027 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2114/E
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
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	
	vector<int> maxn(n),minn(n);
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	auto dfs=[&](this auto &&self,int u=0,int fa=-1) -> void {
		maxn[u]=a[u];
		minn[u]=a[u];
		if (fa != -1) {
			maxn[u]=max(maxn[u],maxn[u]-minn[fa]);
			minn[u]=min(minn[u],minn[u]-maxn[fa]);
		}
		for(auto v : adj[u]) {
			if (v == fa) continue;
			self(v,u);
		}
	};
	dfs();
	for(auto e1 : maxn) cout<<e1<<" ";
	cout<<"\n";
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









