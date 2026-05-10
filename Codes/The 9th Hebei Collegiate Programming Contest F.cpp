// Problem: F. 不死国的生命树
// Contest: Codeforces - The 9th Hebei Collegiate Programming Contest
// URL: https://codeforces.com/gym/105909/problem/F
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int N=1e6+5;
int g[N];
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	vector adj(n+1,vector<int>(0));
	for(int i=2;i<=n;i++) {
		int u;
		cin>>u;
		adj[u].push_back(i);
	}
	
	vector f(21,vector<int>(n+1));
	vector<int> deep(n+1);
	auto dfs=[&](auto&& self,int u,int d) -> void {
		deep[u]=d;
		f[0][u]=g[a[u]+1];
		int tmp=g[a[u]];
		g[a[u]]=u;
		for(auto v : adj[u]) {
			self(self,v,d+1);
		}
		g[a[u]]=tmp;
	};
	dfs(dfs,1,1);
	
	for(int i=1;i<=20;i++) {
		for(int u=1;u<=n;u++) {
			f[i][u]=f[i-1][f[i-1][u]];
		}
	}
	
	int q;
	cin>>q;
	while (q--) {
		int s,t;
		cin>>s>>t;
		int cur=s;
		int ans=1;
		for(int i=20;i>=0;i--) {
			if (f[i][cur] == 0 or deep[f[i][cur]] < deep[t]) continue;
			cur=f[i][cur];
			ans+=1<<i;
		}
		cout<<ans<<"\n";
	}
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







