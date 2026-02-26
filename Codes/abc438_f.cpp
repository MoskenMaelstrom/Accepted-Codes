// Problem: F - Sum of Mex
// Contest: AtCoder - AtCoder Beginner Contest 438
// URL: https://atcoder.jp/contests/abc438/tasks/abc438_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

vector<vector<int>> fa;
vector<int> depth;
void build(const vector<vector<int>>& adj, int root) {
	int n=adj.size();
    int m = log2(n) + 1;
    fa.assign(m + 1, vector<int>(n, -1));
    depth.assign(n, -1);
    
    queue<int> q;
    q.push(root);
    depth[root] = 0;
    fa[0][root] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                fa[0][v] = u;
                q.push(v);
            }
        }
    }
    
    for (int k = 1; k <= m; k++) {
        for (int u = 0; u < n; u++) {
            if (fa[k-1][u] != -1) {
                fa[k][u] = fa[k-1][fa[k-1][u]];
            } else {
                fa[k][u] = -1;
            }
        }
    }
}

int lift(int u, int target) {
    int diff = depth[u] - target;
    int k = 0;
    
    while (diff > 0) {
        if (diff & 1) {
            u = fa[k][u];
        }
        diff >>= 1;
        k++;
    }
    return u;
}

int query(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = lift(u, depth[v]);
    if (u == v) return u;
    
    int m = fa.size() - 1;
    for (int k = m; k >= 0; k--) {
        if (fa[k][u] != fa[k][v]) {
            u = fa[k][u];
            v = fa[k][v];
        }
    }
    
    return fa[0][u];
}

int dist(int u, int v) {
    return depth[u]+depth[v]-2*depth[query(u,v)];
}

void solve()
{
	int n;
	cin>>n;
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	build(adj,0);
	vector<int> siz(n,1);
	function<int(int,int)> dfs=[&](int u,int f) {
		for(auto v : adj[u]) {
			if (v == f) continue;
			siz[u]+=dfs(v,u);
		}
		return siz[u];
	};
	dfs(0,-1);
	
	int ans=1;
	int sum=siz[0]-1;
	for(auto v : adj[0]) {
		sum-=siz[v];
		ans+=sum*siz[v];
		ans+=siz[v];
	}
	
	int s=0,t=0;
	for(int u=1;u<n;u++) {
		int d1=dist(s,t);
        int d2=dist(s,u);
        int d3=dist(t,u);
        
        if (d3 == d1+d2) s=u;
        else if (d2 == d1+d3) t=u;
        else if (d1 != d2+d3) break;
		
		if (query(s,t) == t) ans+=(n-siz[lift(s,depth[t]+1)])*siz[s];
		else ans+=siz[s]*siz[t];
	}
	cout<<ans;
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







