// Problem: 
//     P5731 【深基5.习6】蛇形方阵
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5731
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

int a[10][10];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

signed main()
{
	int n,pn;
	memset(a,0,sizeof(a));
	cin>>pn;
	n=pn*pn;
	int num=2;
	int x=0,y=0,fx=0;
	a[0][0]=1;
	while (num != n+1) {
		int nx=x+dx[fx];
		int ny=y+dy[fx];
		if (nx<0 or nx>=pn or ny<0 or ny>=pn or a[nx][ny] != 0) fx=(fx+1)%4;
		else {
			x=nx;
			y=ny;
			a[x][y]=num++;
		}
	}
	for(int i=0;i<pn;i++) {
		for(int j=0;j<pn;j++) {
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}







