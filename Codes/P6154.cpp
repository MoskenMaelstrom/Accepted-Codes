// Problem: P6154 游走
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6154
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int p=998244353;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res=res*base%p;
		base=base*base%p;
	}
	return res;
}

int ny(int num) {
	return Pow(num,p-2);
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector adj(n,vector<int>(0));
	vector<int> deg(n);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
	}
	vector<int> f(n),g(n);
	
	function<int(int)> dfs1=[&](int u) {
		if (g[u] != 0) return g[u];
		if (adj[u].size() == 0) return g[u]=1;
		int res=0;
		for(auto v : adj[u]) {
			res+=dfs1(v);
			res%=p;
		}
		return g[u]=res+1;
	};
	for(int u=0;u<n;u++) dfs1(u);
	
	function<int(int)> dfs2=[&](int u) {
		if (f[u] != 0) return f[u];
		if (adj[u].size() == 0) return f[u]=0;
		int res=0;
		for(auto v : adj[u]) {
			res+=dfs2(v)+g[v];
			res%=p;
		}
		return f[u]=res;
	};
	for(int u=0;u<n;u++) dfs2(u);
	
	int sum1=0,sum2=0;
	for(int u=0;u<n;u++) sum1=(sum1+f[u])%p,sum2=(sum2+g[u])%p;
	cout<<sum1*ny(sum2)%p;
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







