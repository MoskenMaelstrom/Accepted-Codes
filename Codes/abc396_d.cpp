// Problem: D - Minimum XOR Path
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;
const int maxn=INT64_MAX;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector a(n,vector<array<int,2>>(0));
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	int ans=maxn;
	vector<bool> mark(n,0);
	auto dfs=[&](this auto &&self,int x,int res) -> void {
		mark[x]=1;
		for(auto [v,w] : a[x]) {
			if (v == x or mark[v]) continue;
			else if (v == n-1) ans=min(ans,res^w);
			else {
				self(v,res^w);
			}
		}
		mark[x]=0;
	};
	dfs(0,0);
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









