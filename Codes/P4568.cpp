// Problem: P4568 [JLOI2011] 飞行路线
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4568
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector adj(n,vector<array<int,2>>(0));
	
	vector dis(n,vector<int>(k+1,inf));//某状态从St到某点最短距离
	set<array<int,3>> st;//{w,v,mask}
	
	int St,Ed;
	cin>>St>>Ed;
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	dis[St][0]=0;
	st.insert({0,St,0});
	while (!st.empty()) {
		auto [w,u,mask]=*st.begin();
		st.erase(st.begin());
		if (w > dis[u][mask]) continue;
		if (u == Ed) break;
		for(auto [v,cw] : adj[u]) {
			if (mask < k and w < dis[v][mask+1]) {
				dis[v][mask+1]=w;
				st.insert({w,v,mask+1});
			}
			if (w+cw < dis[v][mask]) {
				dis[v][mask]=w+cw;
				st.insert({w+cw,v,mask});
			}
		}
	}
	
	int ans=inf;
	for(int i=0;i<=k;i++) {
		ans=min(ans,dis[Ed][i]);
	}
	cout<<ans;
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









