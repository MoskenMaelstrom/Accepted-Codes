// Problem: 终于再见
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/J
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
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
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	
	int len=*ranges::max_element(deg);
	vector vec(len+1,vector<int>(0));
	for(int i=0;i<n;i++) vec[deg[i]].push_back(i);
	
	vector<int> ans(n);
	vector<int> dist(n,inf);
	queue<int> q;
	for(int d=len;d>=0;d--) {
		for(int u : vec[d]) {
			if (dist[u] == inf) ans[u]=-1;
			else ans[u]=dist[u];
			dist[u]=0;
			q.push(u);
		}
		
		while (!q.empty()) {
			int u=q.front();
			q.pop();
			
			for(int v : adj[u]) {
				if (deg[v] >= d or dist[v] <= dist[u]+1) continue;
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	
	for(auto e1 : ans) cout<<e1<<" ";
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







