// Problem: E. Fairy
// Contest: Codeforces - Codeforces Beta Round 19
// URL: https://codeforces.com/problemset/problem/19/E
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector adj(n,vector<array<int,2>>(0));
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back({v,i});
		adj[v].push_back({u,i});
	}
	
	vector<int> vis(n);
	vector<int> dep(n);
	vector<int> pa(n);
	int sum=0;
	vector<int> c0(n),c1(n);
	int idx;
	function<void(int,int,int)> dfs=[&](int u,int d,int fa) {
		vis[u]=1;
		dep[u]=d;
		pa[u]=fa;
		
		for(auto [v,id] : adj[u]) {
			if (id == fa) continue;
			if (vis[v] == 1) {
				if (dep[u]%2 == dep[v]%2) {
					sum++;
					c1[u]++;
					c1[v]--;
					idx=id;
				}
				else {
					c0[u]++;
					c0[v]--;
				}
			}
			else if (vis[v] == 0) {
				dfs(v,d+1,id);
				c0[u]+=c0[v];
				c1[u]+=c1[v];
			}
		}
		vis[u]=2;
	};
	
	for(int i=0;i<n;i++) {
		if (vis[i] == 0) dfs(i,0,-1);
	}
	
	vector<int> ans;
	if (sum == 0) {
		for(int i=1;i<=m;i++) ans.push_back(i);
	}
	else {
		for(int i=0;i<n;i++) {
			if (pa[i] == -1) continue;
			if (c1[i] == sum and c0[i] == 0) {
				ans.push_back(pa[i]+1);
			}
		}
		if (sum == 1) {
			ans.push_back(idx+1);
		}
	}
	
	ranges::sort(ans);
	cout<<ans.size()<<"\n";
	for(auto e1 : ans) {
		cout<<e1<<" ";
	}
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







