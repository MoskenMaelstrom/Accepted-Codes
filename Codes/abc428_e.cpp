// Problem: E - Farthest Vertex
// Contest: AtCoder - AtCoder Beginner Contest 428
// URL: https://atcoder.jp/contests/abc428/tasks/abc428_e
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
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> dis;
	auto bfs=[&](int s) -> int {
		dis.assign(n,-1);
	    queue<int> q;
	    q.push(s);
	    dis[s] = 0;
	    
	    while (!q.empty()) {
	        int u = q.front();
	        q.pop();
	        
	        for (auto v : adj[u]) {
	            if (dis[v] == -1) {
	                dis[v]=dis[u]+1;
	                q.push(v);
	            }
	        }
	    }
	    int ans=-1,idx=-1;
	    for(int i=n-1;i>=0;i--) {
	    	if (ans < dis[i]) ans=dis[i],idx=i;
	    }
	    return idx;
	};
	
	vector<int> d1,d2;
	int t1 = bfs(0);
	int t2 = bfs(t1);
	d1=dis;
	t1 = bfs(t2);
	d2=dis;
	for(int i=0;i<n;i++) {
		if (d1[i] < d2[i] or d1[i] == d2[i] and t1 < t2) cout<<t2+1<<"\n";
		else cout<<t1+1<<"\n";
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









