// Problem: Blind Alley
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108301/B
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
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

int dx[]={-1,1,0};
int dy[]={0,0,1};
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector a(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			char c;
			cin>>c;
			a[i][j]=c-'0';
		}
	}
	
	vector vis(n,vector<bool>(m));
	vector dp(n,vector<int>(m,-1));
	vector mark(n,vector<bool>(m));
	auto dfs1=[&](auto&& self,int x,int y) -> void {
		mark[x][y]=1;
		vis[x][y]=1;
		for(int i=0;i<3;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m or a[nx][ny] or mark[nx][ny]) continue;
			self(self,nx,ny);
		}
	};
	dfs1(dfs1,0,0);


	for(int j=m-1;j>=0;j--) {
		for(int i=0;i<n;i++) {
			if (a[i][j] == 0) dp[i][j]=j;
		}
		if (j < m-1) {
			for(int i=0;i<n;i++) {
				if (a[i][j] == 0) dp[i][j]=max(dp[i][j],dp[i][j+1]);
			}	
		}
		for(int i=n-2;i>=0;i--) {
			if (a[i][j] == 0) dp[i][j]=max(dp[i][j],dp[i+1][j]);
		}
		for(int i=1;i<n;i++) {
			if (a[i][j] == 0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (vis[i][j] and dp[i][j] >= j+k-1 and dp[i][j] != m-1) {
				cout<<"Yes\n";
				return;
			}
		}
	}
	cout<<"No\n";
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








