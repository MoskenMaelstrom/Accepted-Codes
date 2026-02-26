#include<bits/stdc++.h>
#define int long long
using namespace std;

struct VBCC {
    int n;
    vector<vector<array<int,2>>> adj;
    vector<array<int,2>> edge;
    vector<int> dfn,low,bel;
    vector<int> stk;
    vector<int> vis;
    int cur,cnt;

    VBCC() {};

    void init(int n) {
        this->n=n;
        adj.assign(n,{});
        edge.clear();
        dfn.assign(n,-1);
        low.assign(n,-1);
        vis.clear();
        stk.clear();
        cur=cnt=0;
    }

    VBCC(int n) {
        init(n);
    }

    void add(int u,int v) {
        adj[u].push_back({v,(int)edge.size()});
        adj[v].push_back({u,(int)edge.size()});
        edge.push_back({u,v});
    }

    void dfs(int u) {
        dfn[u]=low[u]=cur++;
        for (auto [v,pos] : adj[u]) {
            if (vis[pos]) continue;
            vis[pos]=1;
            stk.push_back(pos);
            if (dfn[v] == -1) {
                dfs(v);
                low[u]=min(low[u],low[v]);
                if (low[v] >= dfn[u]) {
                    int y;
                    do {
                        y = stk.back();
                        bel[y] = cnt;
                        stk.pop_back();
                    } while (y != pos);
                    cnt++;
                }
            }
            else low[u]=min(low[u],dfn[v]);
        }
    }

    vector<int> work() {
        bel.assign(edge.size(),-1);
        vis.assign(edge.size(),0);
        for (int i=0;i<n;i++) {
            if (dfn[i] == -1) dfs(i);
        }
        return bel;
    }
    
    vector<set<int>> getEdge() {
    	work();
	    vector<set<int>> E(cnt);
	    for(int i=0;i<edge.size();i++) {
	    	if (bel[i] == -1) continue;
	        auto [u,v]=edge[i];
	        E[bel[i]].insert(i);
	    }
	    return E;
    }
};

void solve()
{
	int n,m;
	cin>>n>>m;
	VBCC bcc(n);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		bcc.add(u,v);
	}
	
	bool ok=1;
	auto edge=bcc.getEdge();
	int len=edge.size();
	set<int> cnt;
	for(int i=0;i<len;i++) {
		map<int,vector<int>> g;
		for(auto pos : edge[i]) {
			auto [u,v]=bcc.edge[pos];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int> p;
		for(auto [u,sons] : g) {
			if (sons.size() > 2) p.push_back(u);
		}
		
		if (p.size() == 0) cnt.insert(edge[i].size());
		if (p.size() > 2) ok=0;
		if (p.size() == 2) {
			set<int> st;
			function<void(int,int,int)> dfs=[&](int u,int fa,int step) {
				if (u == p[1]) {st.insert(step);return;}
				for(auto v : g[u]) {
					if (v == fa) continue;
					dfs(v,u,step+1);
				}
			};
			dfs(p[0],-1,0);
			if (st.size() > 1) ok=0;
			else cnt.insert(2*(*st.begin()));
		}
	}
	
	int c=0;
	for(auto e1 : cnt) {
		if (e1 >= 3) c++;
	}
	if (ok and c <= 1) cout<<"Yes\n";
	else cout<<"No\n";
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







