// Problem: P1434 [SHOI2002] 滑雪
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1434
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<vector<int>> a;
vector<vector<int>> ans;

//返回某点的最大深度
int dfs(int x,int y,int deep)
{
	int maxd=deep;//寻找的是周围最深的深度+当前深度
	for(int i=0;i<4;i++) {
		int nx=x+dx[i],ny=y+dy[i];
		if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
		if (a[nx][ny] < a[x][y] and ans[nx][ny] > 0) maxd=max(ans[nx][ny]+deep,maxd);
		else if (a[nx][ny] < a[x][y]) maxd=max(dfs(nx,ny,deep+1),maxd);
	}
	return maxd;
}

void solve()
{
	cin>>n>>m;
	a.assign(n,vector<int>(m,0));
	ans.assign(n,vector<int>(m,0));
	for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++) 
			cin>>a[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			int deep=1;
			ans[i][j]=dfs(i,j,deep);
		}
	
	// for(int i=0;i<n;i++) {
		// for(int j=0;j<m;j++) {
			// cout<<ans[i][j]<<" ";
		// }
		// cout<<"\n";
	// }		
	
	int maxn=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) 
			maxn=max(maxn,ans[i][j]);
	cout<<maxn;
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









