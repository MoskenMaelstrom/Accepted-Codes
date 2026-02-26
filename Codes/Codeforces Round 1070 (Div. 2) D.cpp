// Problem: D. Fibonacci Paths
// Contest: Codeforces - Codeforces Round 1070 (Div. 2)
// URL: https://codeforces.com/contest/2176/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

const int p=998244353;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector adj(n,vector<array<int,2>>(0));
	vector<array<int,2>> edge;
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		edge.push_back({u,v});
		adj[u].push_back({a[v],i});
	}
	for(int i=0;i<n;i++) {
		ranges::sort(adj[i]);
	}
	
	vector<int> dp(m,-1);
	vector<map<int,int>> mp(n);
	int ans=0;
	function<int(int)> dfs=[&](int id) {
		if (dp[id] != -1) return dp[id];
		int u=edge[id][0];
		int v=edge[id][1];
		int pre=a[u];
		if (mp[v].count(pre)) return dp[id]=mp[v][pre];
		int cur=1;
		auto st=lower_bound(adj[v].begin(),adj[v].end(),array<int,2>{a[u]+a[v],-1});
		auto ed=lower_bound(adj[v].begin(),adj[v].end(),array<int,2>{a[u]+a[v]+1,-1});
		for(auto it=st;it!=ed;it++) {
			auto [val,i]=*it;
			cur+=dfs(i);
			cur%=p;
		}
		
		return dp[id]=mp[v][pre]=cur;
	};
	for(int i=0;i<m;i++) {
		ans+=dfs(i);
		ans%=p;
	}
	cout<<ans<<"\n";
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







