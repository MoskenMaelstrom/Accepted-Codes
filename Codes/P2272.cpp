// Problem: P2272 [ZJOI2007] 最大半连通子图
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2272
// Memory Limit: 125 MB
// Time Limit: 2000 ms
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

//对DAG拓扑排序
vector<int> topo(vector<vector<int>>& adj) {
	int n=adj.size();
	vector<int> deg(n);
	for(int u=0;u<n;u++) {
		for(auto v : adj[u]) deg[v]++;
	}
	
	queue<int> q;
	for(int i=0;i<n;i++) {
		if (deg[i] == 0) q.push(i);
	}
	
	vector<int> order;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		order.push_back(u);
		
		for(auto v : adj[u]) {
			deg[v]--;
			if (deg[v] == 0) q.push(v);
		}
	}
	
	return order;
}

void solve()
{
	int n,m,p;
	cin>>n>>m>>p;
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
	vector<int> siz(len);
	for(int i=0;i<n;i++) {
		siz[bel[i]]++;
	}
	
	auto order=topo(dag);
	vector<int> dp(len),cnt(len);
	int maxn=0,c=0;
	for(auto u : order) {
		if (cnt[u] == 0) cnt[u]=1;
		dp[u]+=siz[u];
		
		if (dp[u] > maxn) {
			maxn=dp[u];
			c=cnt[u];
		}
		else if (dp[u] == maxn) c+=cnt[u],c%=p;
		
		for(auto v : dag[u]) {
			if (dp[u] > dp[v]) {
				dp[v]=dp[u];
				cnt[v]=cnt[u];
			}
			else if (dp[u] == dp[v]) cnt[v]+=cnt[u],cnt[v]%=p;
		}
	}
	cout<<maxn<<"\n"<<c;
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







