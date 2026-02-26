// Problem: F - Eat and Ride
// Contest: AtCoder - AtCoder Beginner Contest 422
// URL: https://atcoder.jp/contests/abc422/tasks/abc422_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> w(n);
	for(int i=0;i<n;i++) cin>>w[i];
	vector adj(n,vector<int>(0));
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector dis(n,vector<int>(n,inf));
	for(int j=0;j<n;j++) dis[0][j]=0; 
	for(int j=n-1;j>=1;j--) {
		for(int u=0;u<n;u++) {
			for(auto v : adj[u]) {
				dis[v][j-1]=min(dis[v][j-1],dis[u][j]+w[u]*j);
			}
		}
	}
	
	for(int i=0;i<n;i++) cout<<dis[i][0]<<"\n";
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









