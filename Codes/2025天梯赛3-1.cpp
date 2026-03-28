#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
int b,n,m,q;
vector<int> dis;
vector<int> a;
void dij(vector<vector<array<int,3>>>& adj,int st) {
	dis.assign(n,inf);
	a.assign(n,0);
	priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;
	dis[st]=0;
	pq.push({0,st});
	while (!pq.empty()) {
		auto [d,u]=pq.top();
		pq.pop();
		if (dis[u] < d) continue;
		for(auto [v,w,val] : adj[u]) {
			if (dis[u]+w < dis[v] or dis[u]+w == dis[v] and a[u]+val > a[v]) {
				dis[v]=dis[u]+w;
				a[v]=a[u]+val;
				pq.push({dis[v],v});
			}
		}
	}
}

void solve()
{
	cin>>b>>n>>m>>q;
	vector adj(n,vector<array<int,3>>(0));
	for(int i=0;i<m;i++) {
		int u,v,w,val;
		cin>>u>>v>>w>>val;
		u--,v--;
		adj[u].push_back({v,w,val});
		adj[v].push_back({u,w,val});
	}
	
	while (q--) {
		int u;
		cin>>u;
		u--;
		dij(adj,u);
		vector<array<int,2>> ans;
		for(int i=0;i<n;i++) {
			if (i != u and dis[i] <= b) ans.push_back({i,a[i]});
		}
		
		if (ans.empty()) cout<<"T_T\n";
		else {
			int maxn=0;
			int cnt=0;
			for(auto [i,val] : ans) {
				if (cnt == 0) cout<<i+1;
				else cout<<" "<<i+1;
				maxn=max(maxn,val);
				cnt++;
			}
			cout<<"\n";
			
			cnt=0;
			for(auto [i,val] : ans) {
				if (val != maxn) continue;
				
				if (cnt == 0) cout<<i+1;
				else cout<<" "<<i+1;
				cnt++;
			}
			cout<<"\n";
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







