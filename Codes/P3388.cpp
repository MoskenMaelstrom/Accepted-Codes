// Problem: P3388 【模板】割点（割顶）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3388
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

struct CutV {
	int n;
	vector<vector<int>> adj;
	vector<int> dfn,low;
	vector<bool> flag;
	int cur;
	
	CutV() {};
	
	void init(int n) {
		this->n=n;
		adj.assign(n,{});
		dfn.assign(n,-1);
		low.assign(n,-1);
		flag.assign(n,0);
		cur=0;
	}
	
	CutV(int n) {init(n);}
	
	void add(int u,int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	void dfs(int u,int fa=-1) {
		dfn[u]=low[u]=cur++;
		int cnt=0;
		for(auto v : adj[u]) {
			if (v == fa) continue;
			if (dfn[v] == -1) {
				cnt++;
				dfs(v,u);
				low[u]=min(low[u],low[v]);
				if (fa != -1 and low[v] >= dfn[u]) flag[u]=1;
			}
			else low[u]=min(low[u],dfn[v]);
		}
		if (fa == -1 and cnt > 1) flag[u]=1;
	}
	
	vector<bool> work() {
		cur=0;
		for(int i=0;i<n;i++) {
			if (dfn[i] == -1) dfs(i,-1);
		}
		return flag;
	}
};

void solve()
{
	int n,m;
	cin>>n>>m;
	CutV cutv(n);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		cutv.add(u,v);
	}
	
	auto flag=cutv.work();
	cout<<ranges::count(flag,1)<<"\n";
	for(int i=0;i<n;i++) {
		if (flag[i]) cout<<i+1<<" ";
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







