// Problem: P1073 [NOIP 2009 提高组] 最优贸易
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1073
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

	

const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	SCC scc(n);
	for(int i=0;i<m;i++) {
		int u,v,o;
		cin>>u>>v>>o;
		u--,v--;
		scc.add(u,v);
		if (o == 2) scc.add(v,u);
	}
	
	auto dag=scc.getDAG();
	auto bel=scc.bel;
	int len=dag.size();
	vector<array<int,2>> w(len,{inf,-inf});//{min,max}
	
	for(int i=0;i<n;i++) {
		int id=bel[i];
		w[id][0]=min(w[id][0],a[i]);
		w[id][1]=max(w[id][1],a[i]);
	}
	int st=bel[0],ed=bel[n-1];
	
	vector<int> deg(len);
	for(int u=0;u<len;u++) {
		for(auto v : dag[u]) deg[v]++;
	}
	queue<int> q;
	q.push(st);
	
	vector<int> order;
	while (!q.empty()) {
		auto u=q.front();
		q.pop();
		order.push_back(u);
		
		for(auto v : dag[u]) {
			deg[v]--;
			if (deg[v] == 0) q.push(v);
		}
	}
	
	for(auto u : order) {
		for(auto v : dag[u]) {
			w[v][0]=min(w[v][0],w[u][0]);
		}
	}
	
	vector<int> dp(len);
	for(auto u : order) {
		dp[u]=max(dp[u],w[u][1]-w[u][0]);
		for(auto v : dag[u]) {
			dp[v]=max(dp[v],dp[u]);
		}
	}
	
	cout<<dp[ed];
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







