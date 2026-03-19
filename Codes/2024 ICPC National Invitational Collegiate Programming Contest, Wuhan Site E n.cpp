// Problem: E. Boomerang
// Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
// URL: https://codeforces.com/gym/105143/problem/E
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int r,t0;
	cin>>r>>t0;
	r--;
	vector<int> dia(n),dep(n),h(n);
	int maxn=0;
	function<void(int,int)> dfs=[&](int u,int fa) {
		int a[2] {};
		for(auto v : adj[u]) {
			if (v == fa) continue;
			dep[v]=dep[u]+1;
			dfs(v,u);
			
			int d=1+h[v];
			for(int i=0;i<2;i++) {
				if (d > a[i]) swap(d,a[i]);
			}
		}
		h[u]=a[0];
		dia[dep[u]+a[1]]=max(dia[dep[u]+a[1]],2*a[1]);
		maxn=max(maxn,a[0]+a[1]);
	};
	dfs(r,r);
	
	for(int i=1;i<n;i++) dia[i]=max(dia[i],min(dia[i-1]+1,maxn));
	for(int i=n-2;i>=0;i--) dia[i]=max(dia[i],dia[i+1]-2);
	
	vector<int> ans(n+1);
	int t=t0;
	for(int k=n;k>=1;k--) {
		while ((t-t0)*k*2 < dia[min(t,n-1)]) t++;
		ans[k]=t;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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







