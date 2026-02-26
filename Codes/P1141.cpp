// Problem: 
//     P1141 01迷宫
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1141
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[1005][1005];
int g[1005][1005];
int tong[1000010];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void dfs(int x,int y,int mark)
{
	g[x][y]=mark;
	for(int i=0;i<4;i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		if (nx < 1 or nx > n or ny < 1 or ny > n) continue;
		if (g[nx][ny] != 0) continue;
		if (a[x][y] != a[nx][ny]) dfs(nx,ny,mark);
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) cin>>a[i][j];
	//标记所有连通块
	int mark=1;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++) {
			if (g[i][j] != 0) continue;
			dfs(i,j,mark++);//mark用来标记不同的连通块方便最后统计，最后有mark-1种连通块
		}
	//用桶统计每个连通块的数量
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) tong[g[i][j]]++;
	//查询
	for(int i=1;i<=m;i++) {
		int x,y;
		cin>>x>>y;
		cout<<tong[g[x][y]]<<endl;
	}
	return 0;
}













