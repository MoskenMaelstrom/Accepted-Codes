// Problem: P1330 封锁阳光大学
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1330
// Memory Limit: 125 MB
// Time Limit: 1000 ms
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
	vector adj(n,vector<int>(0));
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> a(n,-1);
	int cnt0,cnt1;
	bool ok=1;
	function<void(int,int)> dfs=[&](int u,int t) {
		a[u]=t;
		if (t == 0) cnt0++;
		else cnt1++;
		for(auto v : adj[u]) {
			if (a[v] == -1) dfs(v,t^1);
			else if (a[v] == a[u]) ok=0;
		}
	};
	
	int ans=0;
	for(int i=0;i<n;i++) {
		if (a[i] == -1) {
			cnt0=0,cnt1=0;
			dfs(i,0);
			ans+=min(cnt0,cnt1);
		}
	}
	
	if (ok) cout<<ans;
	else cout<<"Impossible";
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







