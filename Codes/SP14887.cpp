// Problem: SP14887 GOODA - Good Travels
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/SP14887
// Memory Limit: 1495 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

//dag_dp算点权max
const int inf=1e18;
int DAG_DP(vector<vector<int>> adj,vector<int> w,int s,int t) {
	int n=adj.size();
	vector<int> deg(n,0);
	for(int u=0;u<n;u++) {
		for(int v : adj[u]) deg[v]++;
	}
	
	queue<int> q;
	for(int i=0;i<n;i++) {
		if (deg[i] == 0) q.push(i);
	}
	
	vector<int> dp(n,-inf);
	dp[s]=w[s];
	
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		
		for(int v : adj[u]) {
			if (dp[u] != -inf) dp[v]=max(dp[v],dp[u]+w[v]);
			deg[v]--;
			if (deg[v] == 0) q.push(v);
		}
	}
	
	return dp[t];
}

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
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	s--,t--;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	SCC scc(n);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		scc.add(u,v);
	}
	
	auto dag=scc.getDAG();
	auto bel=scc.bel;
	int len=dag.size();
	vector<int> w(len);
	for(int i=0;i<n;i++) {
		w[bel[i]]+=a[i];
	}
	
	cout<<DAG_DP(dag,w,bel[s],bel[t]);
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







