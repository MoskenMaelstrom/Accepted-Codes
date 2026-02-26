// Problem: 
//     P1219 [USACO1.5] 八皇后 Checker Challenge
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1219
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n,sum=0;
int ans[15],col[30]={0},Rt[30]={0},Lt[30]={0};
void setvalue(int x,int y,int k)
{
	ans[x] = y;
	col[y] = k;
	Rt[x+y] = k;
	Lt[x-y+n] = k;
}
void dfs(int row)
{
	if (row > n) {
		sum++;
		if (sum <= 3){
			rep(i,n) cout<<ans[i]<<" ";
			cout<<endl;
		}
		return;
	}
	rep(j,n) //对一行里每个数进行枚举
	{
		if (col[j] or Rt[row+j] or Lt[row-j+n]) continue;	//被占用了，过
		setvalue(row,j,1);
		dfs(row+1);
		setvalue(row,j,0);
	}
	
}
signed main()
{
	cin>>n;
	dfs(1);
	cout<<sum;
	return 0;
}












