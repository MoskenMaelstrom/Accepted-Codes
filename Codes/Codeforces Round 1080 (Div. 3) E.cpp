// Problem: E. Idiot First Search
// Contest: Codeforces - Codeforces Round 1080 (Div. 3)
// URL: https://codeforces.com/contest/2195/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int p=1e9+7;
void solve()
{
	int n;
	cin>>n;
	vector adj(n+1,vector<int>(0));
	adj[0].push_back(1);
	for(int i=1;i<=n;i++) {
		int u,v;
		cin>>u>>v;
		if (u == 0) continue;
		adj[i].push_back(u);
		adj[i].push_back(v);
	}
	
	vector<int> cnt(n+1);
	function<int(int)> dfs1=[&](int u) -> int {
		if (adj[u].size() == 0) return 0;
		int res=0;
		for(auto v : adj[u]) res+=dfs1(v),res%=p;
		return cnt[u]=(4+res)%p;
	};
	dfs1(0);
	
	vector<int> ans(n+1);
	ans[1]=(cnt[1]+1)%p;
	function<void(int)> dfs2=[&](int u) {
		for(auto v : adj[u]) {
			ans[v]=ans[u]+cnt[v]+1;
			ans[v]%=p;
			dfs2(v);
		}
	};
	dfs2(1);
	
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
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







