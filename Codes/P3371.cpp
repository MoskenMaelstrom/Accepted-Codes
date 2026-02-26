// Problem: P3371 【模板】单源最短路径（弱化版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3371
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

int inf=(1<<31)-1;
void solve()
{
	int n,m,s;
	cin>>n>>m>>s;
	vector adj(n+1,vector<array<int,2>>(0));
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({w,v});
	}
	set<array<int,2>> st;
	st.insert({0,s});
	vector<int> dis(n+1,inf);
	dis[s]=0;
	vector<int> mark(n+1,0);
	while (!st.empty()) {
		auto [w,v]=*st.begin();
		st.erase(st.begin());
		if (mark[v]) continue;
		else mark[v]=1;
		for(auto [cw,cv] : adj[v]) {
			if (dis[cv] > dis[v]+cw) {
				dis[cv]=dis[v]+cw;
				st.insert({dis[cv],cv});
			}
		}	 
	}
	
	for(int i=1;i<=n;i++) {
		cout<<dis[i]<<" ";
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









