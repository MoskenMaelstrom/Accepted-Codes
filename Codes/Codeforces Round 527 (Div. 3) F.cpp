// Problem: F. Tree with Maximum Cost
// Contest: Codeforces - Codeforces Round 527 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1092/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
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
	auto vec=a;
	function<int(int,int)> dfs1=[&](int u,int fa) {
		for(auto v : adj[u]) {
			if (v == fa) continue;
			vec[u]+=dfs1(v,u);
		}
		return vec[u];
	};
	dfs1(0,0);
	
	vector<int> ans(n);
	function<void(int,int,int)> dfs2=[&](int u,int fa,int deep) {
		for(auto v : adj[u]) {
			if (v == fa) continue;
			ans[0]+=a[v]*deep;
			dfs2(v,u,deep+1);
		}
	};
	dfs2(0,0,1);
	
	function<void(int,int)> dfs3=[&](int u,int fa) {
		for(auto v : adj[u]) {
			if (v == fa) continue;
			ans[v]=ans[u]+vec[0]-vec[v]*2;
			dfs3(v,u);
		}
	};
	dfs3(0,0);
	cout<<*ranges::max_element(ans);
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







