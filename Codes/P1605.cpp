// Problem: 
//     P1605 迷宫
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1605
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
int n,m,t;
int b[15][2],ans=0;
int sx,sy,fx,fy;
int road[10][10];
using namespace std;
void dfs(int x,int y)
{
	if (road[x][y] == 1) {ans++;return;}
	road[x][y]=2;
	if (x >= 1 and road[x-1][y] != 2) dfs(x-1,y);		//上
	if (x <= n-2 and road[x+1][y] != 2) dfs(x+1,y);		//下
	if (y >= 1 and road[x][y-1] != 2) dfs(x,y-1);		//左
	if (y <= m-2 and road[x][y+1] != 2) dfs(x,y+1);		//右
	road[x][y]=0;
}
signed main()
{
	memset(road,0,sizeof(road));
	cin>>n>>m>>t>>sx>>sy>>fx>>fy;
	road[fx-1][fy-1]=1;					//1代表终点
	rep(i,t){
		cin>>b[i][0]>>b[i][1];
		road[b[i][0]-1][b[i][1]-1]=2;	//2代表障碍或走过的路
	}
	dfs(sx-1,sy-1);
	cout<<ans;
	return 0;
}















