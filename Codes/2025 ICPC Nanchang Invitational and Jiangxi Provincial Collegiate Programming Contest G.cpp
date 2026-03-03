// Problem: G. Exploration
// Contest: Codeforces - 2025 ICPC Nanchang Invitational and Jiangxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105911/problem/G
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int inf=1e9;
void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	vector<array<int,3>> edge(m);
	for(int i=0;i<m;i++) {
		auto &[u,v,w]=edge[i];
		cin>>u>>v>>w;
		u--,v--;
	}
	
	vector dp(31,vector<int>(n));
	for(int i=1;i<31;i++) {
		for(int j=0;j<m;j++) {
			auto [u,v,w]=edge[j];
			dp[i][u]=max(dp[i][u],min(inf,dp[i-1][v]*w+w-1));
		}
	}
	
	while (q--) {
		int p,w;
		cin>>p>>w;
		p--;
		for(int i=0;i<31;i++) {
			if (dp[i][p] >= w) {
				cout<<i<<"\n";
				break;
			}
		}
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







