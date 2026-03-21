// Problem: J. Gas Station
// Contest: Codeforces - 2025 ICPC Asia Taiwan Online Programming Contest
// URL: https://codeforces.com/gym/106084/problem/J
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector adj(n,vector<array<int,2>>(0));
	int lo=1;
	for(int i=0;i<n-1;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		lo=max(lo,w);
	}
	
	auto check=[&](int d) -> bool {
		vector<int> a(n);
		function<int(int,int,int)> dfs=[&](int u,int fa,int dis) -> int {
			int f=0;
			int ans=0;
			for(auto [v,w] : adj[u]) {
				if (v == fa) continue;
				ans+=dfs(v,u,w);
				if (f) continue;
				
				if (a[u]+w+a[v] > d) f=1,a[u]=0;
				else a[u]=max(a[u],a[v]+w);
			}
			if (dis+a[u] > d) f=1,a[u]=0;
			return ans+f;
		};
		return dfs(0,-1,0) <= k;
	};
	
	int hi=1e18,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) res=mid,hi=mid-1;
		else lo=mid+1;
	}
	cout<<res;
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







