// Problem: P3386 【模板】二分图最大匹配
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3386
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
struct Flow {
    int n;
    vector<array<int,2>> edge;
    vector<vector<int>> adj;
    vector<int> cur,h;
    
    Flow() {};
    Flow(int n) : n(n) {init(n);}
    
    void init(int n) {
        edge.clear();
        adj.assign(n,{});
        cur.assign(n,0);
        h.assign(n,-1);
    }
    
    void add(int u,int v,int c) {
        adj[u].push_back(edge.size());
        edge.push_back({v,c});
        adj[v].push_back(edge.size());
        edge.push_back({u,0});
    }
    
    bool bfs(int s, int t) {
        h.assign(n,-1);
        queue<int> q;
        h[s]=0;
        q.push(s);
        while (!q.empty()) {
            auto u=q.front();
            q.pop();
            for (auto p : adj[u]) {
                auto [v,c]=edge[p];
                if (c > 0 and h[v] == -1) {
                    h[v]=h[u]+1;
                    if (v == t) return 1;
                    q.push(v);
                }
            }
        }
        return 0;
    }
    
    int dfs(int u,int t,int f) {
        if (u == t) return f;
        int r=f;
        for (int &i=cur[u];i<adj[u].size();i++) {
            int j=adj[u][i];	
            auto [v,c]=edge[j];
            if (c > 0 and h[v] == h[u]+1) {
                int nf=dfs(v,t,min(r,c));
                edge[j][1]-=nf;
                edge[j^1][1]+=nf;
                r-=nf;
                if (r == 0) return f;
            }
        }
        return f-r;
    }
    
    int flow(int s,int t) {
        int ans=0;
        while (bfs(s,t)) {
            cur.assign(n,0);
            ans+=dfs(s,t,inf);
        }
        return ans;
    }
};

void solve()
{
	int n1,n2,m;
	cin>>n1>>n2>>m;
	Flow g(n1+n2+2);
	for(int i=1;i<=n1;i++) g.add(0,i,1);
	for(int i=n1+1;i<=n1+n2;i++) g.add(i,n1+n2+1,1);
	
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		g.add(u,v+n1,1);
	}
	cout<<g.flow(0,n1+n2+1);
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







