// Problem: E. I Just Want... One More...
// Contest: Codeforces - The 2023 ICPC Asia Jinan Regional Contest (The 2nd Universal Cup. Stage 17: Jinan)
// URL: https://codeforces.com/gym/104901/problem/E
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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
    vector<array<int,2>> edge;
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
	Flow f(2*n+2);
	for(int i=1;i<=n;i++) {
		f.add(0,i,1);
		f.add(i+n,2*n+1,1);
	}
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		f.add(u,v+n,1);
	}
	
	f.flow(0,2*n+1);
	vector<bool> vis(2*n+2);
	queue<int> q;
	vis[0]=1;
	q.push(0);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for(auto v : f.adj[u]) {
			if (f.edge[v][1] and !vis[f.edge[v][0]])  {
				vis[f.edge[v][0]]=1;
				q.push(f.edge[v][0]);
			}
		}
	}
	int c1=count(vis.begin()+1,vis.begin()+n+1,1);
	
	vis.assign(2*n+2,0);
	vis[2*n+1]=1;
	q.push(2*n+1);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for(auto v : f.adj[u]) {
			if (f.edge[v^1][1] and !vis[f.edge[v][0]])  {
				vis[f.edge[v][0]]=1;
				q.push(f.edge[v][0]);
			}
		}
	}
	int c2=count(vis.begin()+n+1,vis.begin()+2*n+1,1);
	
	cout<<c1*c2<<"\n";
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







