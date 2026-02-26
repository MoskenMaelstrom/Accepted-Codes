// Problem: C - Peer Review
// Contest: AtCoder - JPRS Programming Contest 2026#1 (AtCoder Beginner Contest 442)
// URL: https://atcoder.jp/contests/abc442/tasks/abc442_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
	
	for(int i=0;i<n;i++) {
		int r=n-1-adj[i].size();
		if (r < 3) cout<<"0 ";
		else cout<<r*(r-1)*(r-2)/6<<" ";
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







