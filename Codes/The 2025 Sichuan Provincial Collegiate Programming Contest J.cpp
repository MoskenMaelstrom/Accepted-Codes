// Problem: J. Sichuan Provincial Contest
// Contest: Codeforces - The 2025 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105949/problem/J
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{	
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector dp(n,vector<int>(5,-1));
	function<int(int,int,int)> dfs=[&](int u,int fa,int step) {
		if (dp[u][step] != -1) return dp[u][step];
		
		int res=0;
		if (step == 0 or step == 1 or step == 3) {
			for(auto v : adj[u]) {
				if (v == fa) continue;
				if (s[v] == 'C') res+=dfs(v,u,step+1);
			}
		}
		else if (step == 2) {
			for(auto v : adj[u]) {
				if (v == fa) continue;
				if (s[v] == 'P') res+=dfs(v,u,step+1);
			}
		}
		else if (step == 4) res=1;
		
		return dp[u][step]=res;
	};
	int ans=0;
	for(int i=0;i<n;i++) {
		if (s[i] == 'S') ans+=dfs(i,i,0);
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







