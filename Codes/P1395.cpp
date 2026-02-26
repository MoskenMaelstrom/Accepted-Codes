// Problem: P1395 会议
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1395
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18;
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
	
	vector<int> pa(n);
	vector<int> siz(n,1);
	function<int(int,int)> dfs1=[&](int u,int fa) {
		pa[u]=fa;
		for(auto v : adj[u]) {
			if (v == fa) continue;
			siz[u]+=dfs1(v,u);
		}
		return siz[u];
	};
	dfs1(0,0);
	
	int id;
	int res=inf;
	for(int u=0;u<n;u++) {
		int cnt=0;
		for(auto v : adj[u]) {
			if (v == pa[u]) continue;
			cnt=max(cnt,siz[v]);
		}
		cnt=max(cnt,n-siz[u]);
		if (cnt < res) res=cnt,id=u;
	}
	
	fill(siz.begin(),siz.end(),1);
	dfs1(id,id);
	vector<int> ans(n);
	function<int(int)> dfs2=[&](int u) {
		for(auto v : adj[u]) {
			if (v == pa[u]) continue;
			ans[u]+=dfs2(v)+siz[v];
		}
		return ans[u];
	};
	dfs2(id);
	cout<<id+1<<" "<<ans[id];
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







