// Problem: C. Roads in Berland
// Contest: Codeforces - Codeforces Beta Round 25 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/25/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	vector dis(n,vector<int>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>dis[i][j];
		}
	}
	
	int q;
	cin>>q;
	while (q--) {
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		int ans=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				dis[i][j]=min({dis[i][j],dis[i][v]+dis[u][j]+w,dis[i][u]+dis[v][j]+w});
				ans+=dis[i][j];
			}
		}
		cout<<ans/2<<" ";
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







