// Problem: C. By the Assignment
// Contest: Codeforces - Codeforces Round 1046 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2135/C
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int p=998244353;
void solve()
{
	int n,m,v;
	cin>>n>>m>>v;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector adj(n,vector<int>(0));
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> pa(n),deep(n),cross(n),ord;
	vector<bool> vis(n);
	function<void(int)> dfs=[&](int u) {
		ord.push_back(u);
		vis[u]=1;
		for(auto v : adj[u]) {
			if (vis[v]) continue;
			pa[v]=u;
			deep[v]=deep[u]+1;
			dfs(v);
		}
	};
	dfs(0);
	
	int ans=1;
	for(int u=0;u<n;u++) {
		for(auto v : adj[u]) {
			if (deep[v] < deep[u]-1) {
				cross[u]++;
				cross[v]--;
				if ((deep[u]-deep[v]+1)&1) {
					if (a[u] > 0) ans=0;
					a[u]=0;
				}
			}
		}
	}
	
	ranges::reverse(ord);
	for(auto u : ord) {
		if (u != 0) cross[pa[u]]+=cross[u];
	}
	
	for(auto u : ord) {
		if (cross[u] > 0) {
			if (a[u] == -1) continue;
			if (a[pa[u]] == -1) a[pa[u]]=a[u];
			else if (a[pa[u]] != a[u]) ans=0;
		}
		else if (a[u] == -1) (ans*=v%p)%=p;
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







