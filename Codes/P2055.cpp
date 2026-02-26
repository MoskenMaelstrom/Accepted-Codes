// Problem: P2055 [ZJOI2009] 假期的宿舍
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2055
// Memory Limit: 125 MB
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
	int n;
	cin>>n;
	Flow g(2*n+2);
	vector<int> mark(n+1);
	for(int i=1;i<=n;i++) {
		cin>>mark[i];
		if (mark[i]) g.add(i+n,2*n+1,1);
	}
	
	vector<int> vec(n+1,1);//回家
	int cnt=0;
	for(int i=1;i<=n;i++) {
		cin>>vec[i];
		if (!vec[i] and mark[i]) {
			g.add(0,i,1);
			g.add(i,i+n,1);
			cnt++;
		}
		else if (!mark[i]) g.add(0,i,1),cnt++;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			int x;
			cin>>x;
			if (x) g.add(i,j+n,1);
		}
	}
	
	if (g.flow(0,2*n+1) == cnt) cout<<"^_^\n";
	else cout<<"T_T\n";	
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







