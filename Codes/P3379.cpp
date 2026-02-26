// Problem: P3379 【模板】最近公共祖先（LCA）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3379
// Memory Limit: 512 MB
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

void solve()
{
	int n,q,root;
	cin>>n>>q>>root;
	root--;
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	build(adj,root);
	while (q--) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		cout<<query(u,v)+1<<"\n";
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









