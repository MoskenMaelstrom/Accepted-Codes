// Problem: C. Max Tree
// Contest: Codeforces - Codeforces Round 1051 (Div. 2)
// URL: https://codeforces.com/contest/2143/problem/C
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
	int n;
	cin>>n;
	vector adj(n,vector<int>(0));
	vector<int> deg(n);
	for(int i=0;i<n-1;i++) {
		int u,v,x,y;
		cin>>u>>v>>x>>y;
		u--,v--;
		if (x < y) {adj[u].push_back(v);deg[v]++;}
		else {adj[v].push_back(u);deg[u]++;}
	}
	queue<int> q;
	for(int i=0;i<n;i++) {
		if (deg[i] == 0) q.push(i);
	}
	vector<int> vec;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		vec.push_back(u);
		for(int v : adj[u]) {
			deg[v]--;
			if (deg[v] == 0) q.push(v);
		}
	}
	vector<int> ans(n);
	for(int i=0;i<n;i++) ans[vec[i]]=i+1;
	for(auto e1 : ans) cout<<e1<<" ";
	cout<<endl;
	
	
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









