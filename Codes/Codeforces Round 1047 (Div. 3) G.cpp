// Problem: G. Cry Me a River
// Contest: Codeforces - Codeforces Round 1047 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2137/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	vector adj(n,vector<int>(0)),fa(n,vector<int>(0));
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		fa[v].push_back(u);
	}
	
	vector<array<bool,2>> dp(n,{1,1});
	vector<array<int,2>> cnt(n);
	
	while (q--) {
		int opt,u;
		cin>>opt>>u;
		u--;
		if (opt == 2) {
			if (dp[u][0]) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else {
			auto dfs=[&](this auto&& self,int p,int mask) -> void {
				if (dp[p][mask] == 0) return;
				dp[p][mask]=0;
				for(int v : fa[p]) {
					cnt[v][1-mask]++;
					if (mask == 1) {
						if (cnt[v][0] == adj[v].size()) self(v,0);
					}
					else self(v,1);
				}
			};
			
			dfs(u,0);
			dfs(u,1);
		}
	}
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









