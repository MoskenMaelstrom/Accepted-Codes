// Problem: D. Shichikuji and Power Grid
// Contest: Codeforces - Codeforces Round 597 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1245/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
vector<int> id,pre;
int Prim(int n,vector<vector<int>>& adj) {
    int res=0;
    vector<int> dist(n,inf);
    vector<bool> vis(n);
    pre.assign(n,0);
    dist[0]=0;
    for (int i=0;i<n;i++) {
        int u=-1;
        for (int j=0;j<n;j++) {
            if (!vis[j] and (u == -1 or dist[j] < dist[u])) u=j;
        }
        if (dist[u] == inf) return -1; 
        vis[u]=1;
        id.push_back(u);
        res+=dist[u];
        for (int v=0;v<n;v++) {
            if (!vis[v] and adj[u][v] < dist[v]) dist[v]=adj[u][v],pre[v]=u;
        }
    }
    return res;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> x(n+1),y(n+1);
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	vector<int> c(n+1),k(n+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>k[i];
	
	vector adj(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++) adj[0][i]=adj[i][0]=c[i];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if (i == j) continue;
			adj[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
		}
	}
	
	cout<<Prim(n+1,adj)<<"\n";
	ranges::sort(id);
	vector<array<int,2>> edge;
	vector<int> p;
	for(int i=1;i<id.size();i++) {
		if (pre[id[i]] == 0) p.push_back(id[i]);
		else edge.push_back({id[i],pre[id[i]]});
	}
	cout<<p.size()<<"\n";
	for(auto u : p) cout<<u<<" ";
	cout<<"\n";
	cout<<edge.size()<<"\n";
	for(auto [u,v] : edge) cout<<u<<" "<<v<<"\n";
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







