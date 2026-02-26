// Problem: F. Skibidus and Slay
// Contest: Codeforces - Codeforces Round 1003 (Div. 4)
// URL: https://codeforces.com/problemset/problem/2065/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> f(n);
	vector<int> ans(n+1,0);
	vector adj(n,vector<int>(0));
	for(int i=0;i<n;i++) cin>>f[i];
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i=0;i<n;i++) {
		set<int> st;
		for(auto e1 : adj[i]) {
			if (f[e1] == f[i]) ans[f[i]]=1;
			else if (st.contains(f[e1])) ans[f[e1]]=1;
			else st.insert(f[e1]);
		}
	}
	
	for(int i=1;i<=n;i++) cout<<ans[i];
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









