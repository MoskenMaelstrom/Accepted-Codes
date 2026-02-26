// Problem: 
//     P1025 [NOIP2001 提高组] 数的划分
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1025
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
void dfs(int num,int sum,int deep)//num为现在举例的数字,sum为当前的合,deep为深度(=k时分类完)
{
	if (deep == k and sum == n) {ans++;return;}
	if (deep >= k or sum >= n) return;
	for(int i=num;((k-deep)*i+sum)<=n;i++) dfs(i,sum+i,deep+1);
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i*k<=n;i++) dfs(i,i,1);
	cout<<ans;
	return 0;
}