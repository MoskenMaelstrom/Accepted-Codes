// Problem: D2. Tree Orientation (Hard Version)
// Contest: Codeforces - Codeforces Round 1086 (Div. 2)
// URL: https://codeforces.com/contest/2208/problem/D2
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
// #define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector a(n,vector<bool>(n));
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		for(int j=0;j<n;j++) {
			a[i][j]=s[j]-'0';
		}
	}
	
	vector<int> cnt(n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cnt[i]+=a[i][j];
		}
	}
	vector<int> ord(n);
	ranges::iota(ord,0);
	sort(ord.begin(),ord.end(),[&](int u,int v) {
		return cnt[u] > cnt[v];
	});
	
	vector<array<int,2>> edge;
	for(int u=0;u<n;u++) {
		vector<bool> vis(n);
		vis[u]=1;
		for(int i=0;i<n;i++) {
			int v=ord[i];
			if (a[u][v] and vis[v] == 0) {
				edge.push_back({u,v});
				if (edge.size() > n-1) {
					cout<<"No\n";
					return;
				}
				for(int w=0;w<n;w++) {
					if (a[v][w]) vis[w]=1;
				}
			}
		}
	}
	// for(int u=0;u<n;u++) {
		// for(int v=0;v<n;v++) {
			// if (u == v and !a[u][v]) f=0;
			// if (u == v or !a[u][v]) continue;
			// bool ok=1;
			// for(int w=0;w<n;w++) {
				// if (w == u or w == v) continue;
				// if (a[w][v] and a[u][w]) ok=0;
			// }
			// if (ok) edge.push_back({u,v});
		// }
	// }
	
	vector adj(n,vector<int>(0));
	for(auto [u,v] : edge) adj[u].push_back(v);
	vector b(n,vector<bool>(n));
	function<void(int,int)> dfs=[&](int u,int id) {
		b[id][u]=1;
		for(auto v : adj[u]) {
			if (b[id][v]) continue;
			dfs(v,id);
		}
	};
	for(int i=0;i<n;i++) dfs(i,i);
	
	adj.assign(n,vector<int>(0));
	for(auto [u,v] : edge) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> vis(n);
	function<void(int)> dfs1=[&](int u) {
		vis[u]=1;
		for(auto v : adj[u]) {
			if (vis[v]) continue;
			dfs1(v);
		}
	};
	dfs1(0);
	
	if (a == b and ranges::count(vis,0) == 0) {
		cout<<"Yes\n";
		for(auto [u,v] : edge) cout<<u+1<<" "<<v+1<<"\n";
	}
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







