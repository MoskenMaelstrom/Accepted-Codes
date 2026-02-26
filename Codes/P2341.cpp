// Problem: P2341 [USACO03FALL / HAOI2006] 受欢迎的牛 G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2341
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

//强联通分量 Strong Connected Conponent
struct SCC {
	int n;
	vector<vector<int>> adj;
	vector<int> dfn,low,bel,stk;
	int cur,cnt;
	SCC() {};
	
	void init(int n) {
		this->n=n;
		adj.assign(n,{});
		dfn.assign(n,-1);
		low.assign(n,-1);
		bel.assign(n,-1);
		stk.clear();
		cur=cnt=0;
	}
	
	SCC(int n) {init(n);}
	
	void add(int u,int v) {	
		adj[u].push_back(v);
	}
	
	void dfs(int x) {
		dfn[x]=low[x]=cur++;
		stk.push_back(x);
		for(auto y : adj[x]) {
			if (dfn[y] == -1) {
				dfs(y);
				low[x]=min(low[x],low[y]);
			}	
			else if (bel[y] == -1){
				low[x]=min(low[x],dfn[y]);
			}
		}
		
		if (dfn[x] == low[x]) {
			int y;
			do {
				y=stk.back();
				bel[y]=cnt;
				stk.pop_back();
			} while (y != x);
			cnt++;
		}
	}
	
	vector<int> work() {
		for(int i=0;i<n;i++) {
			if (dfn[i] == -1) dfs(i);
		}
		return bel;
	}
	
	vector<vector<int>> getDAG() {
		work();
		vector dag(cnt,vector<int>(0));
		for(int u=0;u<n;u++) {
			for(auto v : adj[u]) {
				if (bel[u] != bel[v]) dag[bel[u]].push_back(bel[v]);
			}
		}
		for(int i=0;i<cnt;i++) {
			ranges::sort(dag[i]);
			dag[i].erase(unique(dag[i].begin(),dag[i].end()),dag[i].end());
		}
		return dag;
	}
};

void solve()
{
	int n,m;
	cin>>n>>m;
	SCC scc(n);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		scc.add(u,v);
	}
	
	auto dag=scc.getDAG();
	int len=dag.size();
	
	set<int> st;
	for(int i=0;i<len;i++) {
		if (dag[i].size() == 0) st.insert(i);
	}
	if (st.size() > 1) {cout<<"0\n";return;}
	
	int ans=0;
	auto bel=scc.bel;
	for(int i=0;i<n;i++) {
		if (st.contains(bel[i])) ans++;
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







