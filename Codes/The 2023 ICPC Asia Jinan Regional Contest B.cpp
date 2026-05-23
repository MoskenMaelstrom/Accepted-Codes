// Problem: B. Graph Partitioning 2
// Contest: Codeforces - The 2023 ICPC Asia Jinan Regional Contest (The 2nd Universal Cup. Stage 17: Jinan)
// URL: https://codeforces.com/gym/104901/problem/B
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;
using namespace __gnu_pbds;

const int p=998244353;
void solve()
{
	int n,k;
	cin>>n>>k;
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<gp_hash_table<int,int>> f(n);
	auto dfs=[&](auto&& self,int u,int fa) -> void {
		f[u][1]=1;
		for(auto v : adj[u]) {
			if (v == fa) continue;
			self(self,v,u);
			gp_hash_table<int,int> g;
			for(auto [s1,c1] : f[v]) {
				if (s1 >= k) {
					for(auto [s2,c2] : f[u]) {
						(g[s2]+=c1*c2%p)%=p;
					}
				}
				for(auto [s2,c2] : f[u]) {
					if (s1+s2 > k+1) continue;
					(g[s1+s2]+=c1*c2%p)%=p;
				}	
			}
			swap(f[u],g);
			f[v].clear();
		}
	};
	
	dfs(dfs,0,-1);
	cout<<((f[0][k]+f[0][k+1])%p+p)%p<<"\n";
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







