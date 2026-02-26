// Problem: 
//     P4147 玉蟾宫
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4147
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char a[N][N];
int h[N][N];//悬线高度
int l[N][N],r[N][N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		cin>>a[i][j];
		h[i][j]=1;
		l[i][j]=j;
		r[i][j]=j;
	}
	//分行处理
	for(int i=1;i<=n;i++) {
		//处理l
		for(int j=2;j<=m;j++)
			if (a[i][j] == 'F' and a[i][j-1] == 'F') l[i][j]=l[i][j-1];
		//处理r
		for(int j=m-1;j>=1;j--)
			if (a[i][j] == 'F' and a[i][j+1] == 'F') r[i][j]=r[i][j+1];
		//处理h
		for(int j=1;j<=m;j++)
			if (a[i][j] == 'F' and a[i-1][j] == 'F') h[i][j]=h[i-1][j]+1;
	}
	//开始计算每条悬线的l和r
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++) {
			if (a[i][j] == 'F' and a[i-1][j] == 'F'){
				l[i][j]=max(l[i][j],l[i-1][j]);
				r[i][j]=min(r[i][j],r[i-1][j]);
			}
		}
	//计算最大面积
	int ans=0;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++)
			if (a[i][j] == 'F') ans=max(ans,(r[i][j]-l[i][j]+1)*h[i][j]);
	cout<<ans*3;
	return 0;
}








