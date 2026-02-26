// Problem: 
//     P1101 单词方阵
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1101
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n;
char a[105][105];
int mark[105][105];
string ss="yizhong";
void dfs(int x,int y,int step,int fx)
{
	if (step == 7) {	//回溯标记
		if (fx == 0) rep(i,7) mark[x+1+i][y] = 1;
		else if (fx == 1) rep(i,7) mark[x+1+i][y-1-i]=1;
		else if (fx == 2) rep(i,7) mark[x][y-1-i]=1;
		else if (fx == 3) rep(i,7) mark[x-1-i][y-1-i]=1;
		else if (fx == 4) rep(i,7) mark[x-1-i][y]=1;
		else if (fx == 5) rep(i,7) mark[x-1-i][y+1+i]=1;
		else if (fx == 6) rep(i,7) mark[x][y+1+i]=1;
		else if (fx == 7) rep(i,7) mark[x+1+i][y+1+i]=1;
		return;
	}
	if (ss[step] != a[x][y]) return;
	if (fx == 0) dfs(x-1,y,step+1,0);
	else if (fx == 1) dfs(x-1,y+1,step+1,1);
	else if (fx == 2) dfs(x,y+1,step+1,2);
	else if (fx == 3) dfs(x+1,y+1,step+1,3);
	else if (fx == 4) dfs(x+1,y,step+1,4);
	else if (fx == 5) dfs(x+1,y-1,step+1,5);
	else if (fx == 6) dfs(x,y-1,step+1,6);
	else if (fx == 7) dfs(x-1,y-1,step+1,7);
}
signed main()
{
	cin>>n;
	memset(mark,0,sizeof(mark));
	rep(i,n)
		rep(j,n) cin>>a[i][j];
	rep(i,n)
		rep(j,n){
			if (i >= 6) 				dfs(i,j,0,0);//上
			if (i >= 6 and j+6<=n-1) 	dfs(i,j,0,1);//右上
			if (j+6<=n-1)				dfs(i,j,0,2);//右
			if (i+6<=n-1 and j+6<=n-1) 	dfs(i,j,0,3);//右下
			if (i+6<=n-1) 				dfs(i,j,0,4);//下
			if (i+6<=n-1 and j >= 6) 	dfs(i,j,0,5);//左下
			if (j >= 6) 				dfs(i,j,0,6);//左
			if (i >= 6 and j >= 6) 		dfs(i,j,0,7);//左上
		}
	rep(i,n){
		rep(j,n){
			if (mark[i][j]) cout<<a[i][j];
			else cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}









