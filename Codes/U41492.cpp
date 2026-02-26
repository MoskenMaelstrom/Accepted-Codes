// Problem: U41492 树上数颜色
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U41492
// Memory Limit: 125 MB
// Time Limit: 1200 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector adj(n+1,vector<int>(0));
	for(int i=1;i<=n-1;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> c(n+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	
	vector<int> ans(n+1),cnt(n+1),siz(n+1),fa(n+1),son(n+1);
	int diff=0,flag=0;
	function<void(int,int)> get_info=[&](int u,int f)
	{
	    fa[u]=f;
	    siz[u]=1;
	    for (auto v : adj[u]) {
	        if (v == f) continue;
	        get_info(v,u);
	        siz[u]+=siz[v];
	        if (siz[v] > siz[son[u]]) son[u]=v;
	    }
	};
	get_info(1,0);
	
	function<void(int,int,int)> count=[&](int u,int f,int val) {
	    cnt[c[u]]+=val;
	    if (cnt[c[u]] == 0) diff--;
	    else if (cnt[c[u]] == 1) diff++;
	    for (auto v : adj[u]) {
	        if (v == f or v == flag) continue;
	        count(v,u,val);
	    }
	};
	
	function<void(int,int,bool)> dfs=[&](int u,int f,bool ok) {
	    for (auto v : adj[u]) {
	        if (v == f or v == son[u]) continue;
	        dfs(v,u,0);
	    }
	    if (son[u]) dfs(son[u],u,1),flag=son[u];
	    count(u,f,1);
	    ans[u]=diff;
	    flag=0;
	    if (ok == 0) {
	        count(u,f,-1);
	        diff=0;
	    }
	};
	dfs(1,0,0);
	
	int q;
	cin>>q;
	while (q--) {
		int u;
		cin>>u;
		cout<<ans[u]<<"\n";
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







