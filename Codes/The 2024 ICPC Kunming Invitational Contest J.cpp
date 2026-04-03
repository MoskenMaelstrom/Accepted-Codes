#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector adj(n,vector<array<int,3>>(0));
	for (int i=0;i<m;i++) {
		int u,v,c,w;
		cin>>u>>v>>c>>w;
		u--,v--,c--;
		adj[u].push_back({v,w,c});
		adj[v].push_back({u,w,c});
	}

	vector<bool> vis(n);
	vis[0]=1;
	vector<priority_queue<array<int,2>,vector<array<int,2>>,greater<>>> pq(m);	
	for(auto [v,w,c] : adj[0]) pq[c].push({w,v});

	for(int i=0;i<k;i++) {
		int id,len;
		cin>>id>>len;
		id--;
		vector<array<int,2>> vec;
		while (!pq[id].empty() and pq[id].top()[0]<=len) {
			auto [w1,u]=pq[id].top();
			pq[id].pop();
			if (vis[u]) continue;
			vis[u]=1;
			for(auto [v,w2,c] : adj[u]) {
				if (vis[v]) continue;
				if (c == id) {
					pq[id].push({w1+w2,v});
					vec.push_back({w2,v});
				}
				else pq[c].push({w2,v});
			}
		}
		for(auto [w,v] : vec) pq[id].push({w,v});
	}
	for(int i=0;i<n;i++) cout<<vis[i];
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







