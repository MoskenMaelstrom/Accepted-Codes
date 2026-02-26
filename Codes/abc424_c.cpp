// Problem: C - New Skill Acquired
// Contest: AtCoder - AtCoder Beginner Contest 424
// URL: https://atcoder.jp/contests/abc424/tasks/abc424_c
// Memory Limit: 1024 MB
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
	int n;
	cin>>n;
	vector adj(n+1,vector<int>(0));
	for(int i=1;i<=n;i++) {
		int x,y;
		cin>>x>>y;
		adj[x].push_back(i);
		adj[y].push_back(i);
	}
	
	vector<bool> mark(n+1);
	auto dfs=[&](auto self,int u) -> void {
		for(auto v : adj[u]) {
			if (mark[v]) continue;
			mark[v]=1;
			self(self,v);
		}
	};
	dfs(dfs,0);
	cout<<ranges::count(mark,1);
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









