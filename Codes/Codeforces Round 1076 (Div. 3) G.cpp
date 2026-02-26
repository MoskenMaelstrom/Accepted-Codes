// Problem: G. Paths in a Tree
// Contest: Codeforces - Codeforces Round 1076 (Div. 3)
// URL: https://codeforces.com/contest/2193/problem/G
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

int query(int x,int y) {
	cout<<"? "<<x+1<<" "<<y+1<<endl;
	int res;
	cin>>res;
	return res;
}

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
	
	int ans=-1;
	function<int(int,int)> dfs=[&](int u,int fa) -> int {
		int cur=u;
		for(auto v : adj[u]) {
			if (v == fa) continue;
			int w=dfs(v,u);
			if (ans != -1) return -1;
			if (w == -1) continue;
			
			if (cur == -1) cur=w;
			else {
				if (query(cur,w)) {
					if (query(cur,cur)) ans=cur;
					else ans=w;
					return -1;
				}
				else cur=-1;
			}
		}
		return cur;
	};
	
	int u=dfs(0,-1);
	if (ans == -1) ans=u;
	cout<<"! "<<ans+1<<endl;
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







