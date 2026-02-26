// Problem: 
//     P1433 吃奶酪
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1433
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const double MAX=1e9;
int n;
double dis=0,mindis=MAX;
double a[20][2],mark[20]={0};
double d[20][20];
double dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void dfs(int x)
{
	int flag = 1;
	if (dis>=mindis) return;
	rep(j,n) if (mark[j] == 0) {flag=0;break;}
	if (flag) {mindis=min(dis,mindis);return;}
	rep(i,n){
		if (mark[i] == 1) continue;
		mark[i]=1;		//决定走向a[i]坐标
		dis+=d[x][i];
		dfs(i);
		mark[i]=0;		//暂时不向a[i]走
		dis-=d[x][i];
	}
}
signed main()
{
	cin>>n;
	rep(i,n) cin>>a[i][0]>>a[i][1];
	rep(i,n)//i点与j点的距离
		rep(j,n) {
			d[i][j]=dist(a[i][0],a[i][1],a[j][0],a[j][1]);
			d[j][i]=d[i][j];
		}
	rep(i,n) {
		mark[i]=1;
		dis+=dist(0,0,a[i][0],a[i][1]);
		dfs(i);
		mark[i]=0;
		dis-=dist(0,0,a[i][0],a[i][1]);
	}
	printf("%.2f",mindis);
	return 0;
}













