// Problem: Y. Xor-Paths
// Contest: Codeforces - Mashup Dynamic Programming Contest 1
// URL: https://codeforces.com/gym/669897/problem/Y
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector a(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>a[i][j];
		}
	}
	
	int ans=0;
	vector mp(n+1,vector<unordered_map<int,int>>(m+1));
	int hf=(n+m-2)/2;
	auto dfs1=[&](auto&& self,int x,int y,int val) -> void {
		if (x+y-2 == hf) {
			mp[x][y][val]++;
			return;
		}
		if (x < n) self(self,x+1,y,val^a[x+1][y]);
		if (y < m) self(self,x,y+1,val^a[x][y+1]);
	};
	dfs1(dfs1,1,1,a[1][1]);
	
	auto dfs2=[&](auto&& self,int x,int y,int val) -> void {
		if (x+y-2 == hf) {
			ans+=mp[x][y][k^val^a[x][y]];
			return;
		}
		if (x > 1) self(self,x-1,y,val^a[x-1][y]);
		if (y > 1) self(self,x,y-1,val^a[x][y-1]);
	};
	dfs2(dfs2,n,m,a[n][m]);
	
	cout<<ans;
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







