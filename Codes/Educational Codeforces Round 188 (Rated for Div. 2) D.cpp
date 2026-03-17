// Problem: D. Alternating Path
// Contest: Codeforces - Educational Codeforces Round 188 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2204/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector adj(n,vector<int>(0));
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> vec(n,-1);
	int ans=0;
	for(int i=0;i<n;i++) {
		if (vec[i] != -1) continue;
		queue<int> q;
		q.push(i);
		vec[i]=0;
		
		int c0=0,c1=0;
		bool f=1;
		while (!q.empty()) {
			int u=q.front();
			q.pop();
			if (vec[u]) c1++;
			else c0++;
			for(auto v : adj[u]) {
				if (vec[v] == -1) vec[v]=1-vec[u],q.push(v);
				else if (vec[v] == vec[u]) f=0;
			}
		}
		if (f) ans+=max(c0,c1);
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







