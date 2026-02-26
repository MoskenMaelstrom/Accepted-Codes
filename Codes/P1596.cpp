// Problem: 
//     P1596 [USACO10OCT] Lake Counting S
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1596
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,m,ans=0;
char a[105][105];
void dfs(int x,int y)
{
	if (a[x][y] != 'W') return;
	a[x][y]='A';
	if (x > 0) dfs(x-1,y);
	if (y > 0) dfs(x,y-1);
	if (x > 0 and y > 0) dfs(x-1,y-1);
	if (x < n-1) dfs(x+1,y);
	if (y < m-1) dfs(x,y+1);
	if (x < n-1 and y < m-1) dfs(x+1,y+1);
	if (x < n-1 and y > 0) dfs(x+1,y-1);
	if (x > 0 and y < m-1) dfs(x-1,y+1);
}
signed main()
{
	cin>>n>>m;
	rep(i,n)
		rep(j,m) cin>>a[i][j];
	rep(i,n)
		rep(j,m)
			if (a[i][j] == 'W') {dfs(i,j);ans++;}
	cout<<ans;
	return 0;
}




