// Problem: 
//     P1162 填涂颜色
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1162
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
int a[35][35];
int n;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void dfs(int x,int y)
{
	a[x][y]=2;
	for(int i=0;i<4;i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		if (nx < 0 or nx > n+1 or ny < 0 or ny > n+1 or a[nx][ny] != 0) continue;
		else dfs(nx,ny);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	
	dfs(0,0);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if (a[i][j] == 0) cout<<"2 ";
			else if (a[i][j] == 1) cout<<"1 ";
			else cout<<"0 ";
		}
		cout<<"\n";
	}
	return 0;
}











