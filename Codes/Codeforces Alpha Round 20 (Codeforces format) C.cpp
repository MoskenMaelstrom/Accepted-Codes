// Problem: C. Dijkstra?
// Contest: Codeforces - Codeforces Alpha Round 20 (Codeforces format)
// URL: https://codeforces.com/problemset/problem/20/C
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

vector<int> pa;
const int inf=1e18;
vector<int> dijkstra(vector<vector<array<int,2>>> &adj,int st) {
    int n=adj.size();
    vector<int> dis(n,inf);
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;
    dis[st]=0;
    pq.push({0,st});
    while (!pq.empty()) {
        auto [d,u]=pq.top();
        pq.pop();
        if (d > dis[u]) continue;
        for (auto &[v,w] : adj[u]) {
            if (dis[u]+w < dis[v]) {
            	pa[v]=u;
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
    return dis;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	pa.assign(n,-1);
	vector adj(n,vector<array<int,2>>(0));
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	auto dis=dijkstra(adj,0);
	
	if (dis[n-1] >= inf) cout<<"-1";
	else {
		vector<int> ans;
		int u=n-1;
		while (u != 0) {
			ans.push_back(u);
			u=pa[u];
		}
		ranges::reverse(ans);
		cout<<1<<" ";
		for(auto u : ans) cout<<u+1<<" ";
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







