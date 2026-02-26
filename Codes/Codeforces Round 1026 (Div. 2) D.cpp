// Problem: D. Fewer Batteries
// Contest: Codeforces - Codeforces Round 1026 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2110/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	int n,m;
	cin>>n>>m;
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>b[i];
	
	vector adj(n,vector<array<int,2>>(0));
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].push_back({v,w});
	}
	
	auto check=[&](int k) {
		vector<int> dp(n);
		dp[0]=min(k,b[0]);
		for(int i=0;i<n;i++) {
			for(auto [v,w] : adj[i]) {
				if (dp[i] < w) continue;
				dp[v]=max( dp[v],min(k,dp[i]+b[v]) );
			}
		}
		 return dp[n-1] > 0;
	};
	
	int lo=0,hi=1e9,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) hi=mid-1,res=mid;
		else lo=mid+1;
	}
	
	cout<<res<<"\n";
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









