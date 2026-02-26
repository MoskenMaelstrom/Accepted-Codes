// Problem: D. Cost of Tree
// Contest: Codeforces - Codeforces Round 1081 (Div. 2)
// URL: https://codeforces.com/contest/2192/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
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
	
	vector<int> pa(n);
	vector<int> siz(n);
	function<int(int,int)> dfs=[&](int u,int fa) {
		pa[u]=fa;
		siz[u]=a[u];
		for(auto v : adj[u]) {
			if (v == fa) continue;
			siz[u]+=dfs(v,u);
		}
		return siz[u];
	};
	dfs(0,0);
	
	vector<int> val(n);
	vector<int> d1(n),d2(n);
	function<int(int,int)> dfs1=[&](int u,int fa) {
		int res=0;
        d1[u]=d1[fa]+1;
        d2[u]=d1[u];
		for(auto v : adj[u]) {
			if (v == fa) continue;
			res+=dfs1(v,u)+siz[v];
            d2[u]=max(d2[v],d2[u]);
		}
		return val[u]=res;
	};
	dfs1(0,0);
	
	vector<int> ans(n);
	function<void(int,int)> dfs2=[&](int u,int fa) {
		int res=val[u];
		int D=0,DD=0;
		for(auto v : adj[u]) {
			if (v == fa) continue;
			if (d2[v] >= D) DD=D,D=d2[v];
			else if (d2[v] >= DD) DD=d2[v];
			dfs2(v,u);
		}
		
		ans[u]=res;
		for(auto v : adj[u]) {
			if (v == fa) continue;
			if (D == d2[v]) ans[u]=max(ans[u],res-siz[v]+siz[v]*(DD-d1[u]+1));
			else ans[u]=max(ans[u],res-siz[v]+siz[v]*(D-d1[u]+1));
			ans[u]=max(ans[u],res-val[v]+ans[v]);
		}
	};
	dfs2(0,0);
	
	for(auto e1 : ans) cout<<e1<<" ";
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







