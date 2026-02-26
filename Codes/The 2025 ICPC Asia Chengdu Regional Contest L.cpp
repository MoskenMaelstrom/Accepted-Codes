#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	
	vector adj(n+1,vector<int>(0));
	for(int i=1;i<=n-1;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	//1-based
	vector<int> ans(n+1),cnta(n+1),cntb(n+1),siz(n+1),fa(n+1),son(n+1);
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
		cnta[a[u]]+=val;
		if (a[u] == 0) diff-=val;
		else {
			if (val == -1 and cnta[a[u]] >= cntb[a[u]]) diff--;
			if (val == -1 and cnta[a[u]] < cntb[a[u]]) diff++;
			if (val == 1 and cnta[a[u]] > cntb[a[u]]) diff++;
			if (val == 1 and cnta[a[u]] <= cntb[a[u]]) diff--;
		}
		
		cntb[b[u]]+=val;
		if (b[u] == 0) diff-=val;
		else {
			if (val == -1 and cntb[b[u]] >= cnta[b[u]]) diff--;
			if (val == -1 and cntb[b[u]] < cnta[b[u]]) diff++;
			if (val == 1 and cntb[b[u]] > cnta[b[u]]) diff++;
			if (val == 1 and cntb[b[u]] <= cnta[b[u]]) diff--;
		}
	    
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

	for(int i=1;i<=n;i++) {
		cout<<(ans[i] <= 0 ? 1 : 0);
	}
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








