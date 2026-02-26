// Problem: D. Arboris Contractio
// Contest: Codeforces - Codeforces Round 1042 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2131/D
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

const int inf=1e18;
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
	
	int leaf=0;
	for(int i=0;i<n;i++) {
		leaf+=adj[i].size() == 1;
	}
	
	int ans=inf;
	for(int i=0;i<n;i++) {
		int cnt=adj[i].size()==1;
		for(auto e1 : adj[i]) {
			if (adj[e1].size() == 1) cnt++;
		}
		ans=min(ans,leaf-cnt);
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









