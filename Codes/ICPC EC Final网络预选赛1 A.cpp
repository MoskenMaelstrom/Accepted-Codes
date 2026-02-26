#include<bits/stdc++.h>
using namespace std;


void solve() 
{
	int n,m;
	cin>>n>>m;
	vector adj(n,vector<array<int,2>>(0));
	for(int i=0;i<n-1;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	vector<array<int,2>> b(m);
	for(int i=0;i<m;i++) {
		cin>>b[i][0]>>b[i][1];
		b[i][0]--;
		b[i][1]--;
	}
	
	
	vector fa(n,vector<int>(2,-1));
	fa[0]={0,0};
	vector<int> dist(n);
	vector<int> cha(n);
	
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for(auto [v,w] : adj[u]) {
			if (fa[v][0] != -1) continue;
			dist[v]=dist[u]+w;
			fa[v][0]=u;
			fa[v][1]=w;
			q.push(v);
		}
	}
	
	vector<int> dp(n);
	vector<bool> mark(n);
	mark[0]=1;
	for(auto [e1,e2] : adj[0]) q.push(e1);
	while (!q.empty()) {
		auto u=q.front();
		q.pop();
		mark[u]=1;
		dp[u]=dp[fa[u][0]]+fa[u][1];
		for(int i=0;i<m;i++) {
			if (b[i][0] == u) dp[u]=min(dp[u],dist[b[i][1]]);
			if (b[i][1] == u) dp[u]=min(dp[u],dist[b[i][0]]);
		}
		for(auto [v,w] : adj[u]) {
			if (mark[v]) continue;
			q.push(v);
		}
	}
	
	int sum=0;
	for(int i=0;i<n;i++) cout<<dist[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++) cout<<dp[i]<<" ";
	cout<<endl;
	
	for(int i=0;i<n;i++) sum+=dist[i];
	for(int i=0;i<n;i++) cha[i]=dist[i]-dp[i];
	sort(cha.begin(),cha.end());
	cout<<sum<<"\n";
	for(int i=n-1;i>=0;i--) {
		sum-=cha[i];
		cout<<sum<<"\n";
	}
	
}

signed main() 
{
	ios::sync_with_stdio();
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}