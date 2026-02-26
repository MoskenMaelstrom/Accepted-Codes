// Problem: F. Cherry Tree
// Contest: Codeforces - Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/contest/2184/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
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
	
	function<int(int,int)> dfs=[&](int u,int fa) {
		int mask=1;
		bool flag=1;
		
		for(auto v : adj[u]) {
			if (v == fa) continue;
			flag=0;
			int cur=0;
			int m=dfs(v,u);
			for(int i=0;i<3;i++) {
				if (((mask>>i)&1) == 0) continue;
				for(int j=0;j<3;j++) {
					if ((m>>j)&1) cur|=(1<<((i+j)%3));
				}
			}
			mask=cur;
		}
		if (flag) return 2ll;
		else return mask|2;
	};
	
	int ans=dfs(0,0);
	if (ans&1) cout<<"YES\n";
	else cout<<"NO\n";
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







