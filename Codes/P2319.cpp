// Problem: P2319 [HNOI2006] 超级英雄
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2319
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
struct Flow {
    int n;
    vector<array<int,2>> edge;//[v,残量]
    vector<vector<int>> adj;
    vector<int> cur,h;
    
    Flow() {};
    Flow(int n) : n(n) {init(n);}
    
    void init(int n) {
        edge.clear();
        if (adj.size() < n) adj.resize(n);
        for(auto &e : adj) e.clear();
        if (cur.size() < n) cur.resize(n);
        if (h.size() < n) h.resize(n);
    }
    
    void add(int u,int v,int c) {
        adj[u].push_back(edge.size());
        edge.push_back({v,c});
        adj[v].push_back(edge.size());
        edge.push_back({u,0});
    }
    
    bool bfs(int s, int t) {
    	fill(h.begin(),h.end(),-1);
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
        	fill(cur.begin(),cur.end(),0);
            ans+=dfs(s,t,inf);
        }
        return ans;
    }
};

void solve()
{
	int n,m;
	cin>>n>>m;
	Flow flow(m+n+2);
	for(int i=0;i<n;i++) {
		flow.add(m+1+i,m+n+1,1);
	}
	
	int ans=0;
	for(int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		flow.add(0,i,1);
		flow.add(i,m+1+u,1);
		flow.add(i,m+1+v,1);
		if (flow.flow(0,n+m+1) == 0) break;
		ans++;
	}
	cout<<ans<<"\n";
	
	for(int i=1;i<=ans;i++) {
		for(auto id : flow.adj[i]) {
			if (id&1) continue;
			auto [v,c]=flow.edge[id];
			if (c == 0) {
				cout<<v-m-1<<"\n";
				break;
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







