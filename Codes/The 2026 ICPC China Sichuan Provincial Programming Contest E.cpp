// Problem: E. 永恒的奥古斯都
// Contest: Codeforces - The 2026 ICPC China Sichuan Provincial Programming Contest
// URL: https://codeforces.com/gym/106570/problem/E
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> p2(n+1);
	p2[0]=1;
	for(int i=1;i<=n;i++) {
		p2[i]=p2[i-1]*2%p;
	}
	
	vector<int> dp(n,1);
	vector<int> siz(n,1);
	auto dfs=[&](auto&& self,int u,int fa) -> void {
		for(auto v : adj[u]) {
			if (v == fa) continue;
			self(self,v,u);
			siz[u]+=siz[v];
			(dp[u]*=dp[v])%=p;
		}
		if (a[u]) (dp[u]+=p2[siz[u]-1])%=p;
	};
	dfs(dfs,0,-1);
	cout<<dp[0]<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







