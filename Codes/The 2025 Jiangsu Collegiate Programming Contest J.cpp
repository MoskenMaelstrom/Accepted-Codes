// Problem: J. Puzzle Competition
// Contest: Codeforces - The 2025 Jiangsu Collegiate Programming Contest, The 2025 Guangdong Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105945/problem/J
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n);
	priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
	
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if (a[i] == 0) pq.push({0,i,1});
	}
	
	for(int i=0;i<k;i++) {
		int t,sc;
		cin>>t>>sc;
		for(int j=0;j<sc;j++) {
			int u;
			cin>>u;
			u--;
			pq.push({t,u,inf});
		}
	}
	
	vector adj(n,vector<array<int,2>>(0));
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].push_back({v,w});
	}
	
	vector<int> ans(n,inf);
	vector<int> cur(n);
	while (!pq.empty()) {
		auto [t,u,w]=pq.top();
		pq.pop();
		if (ans[u] < inf) continue;
		cur[u]+=w;
		if (cur[u] >= a[u]) {
			ans[u]=t;
			for(auto [v,W] : adj[u]) {
				pq.push({t+W,v,1});
			}
		}
	}
	for(int i=0;i<n;i++) {
		if (ans[i] == inf) cout<<"-1 ";
		else cout<<ans[i]<<" ";
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







