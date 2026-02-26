// Problem: 
//     P1638 逛画展
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1638
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int mark[2005]={0};
int sum=0;
int ans=0x7fffffff;
int ansh,anst;
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int head=1,tail=2;//初始化队列
	while (tail != n+2) {
		mark[a[tail-1]]++;
		if (mark[a[tail-1]] == 1) sum++;//新增之前没出现的数
		while (mark[a[head]] > 1) {mark[a[head]]--;head++;}
		
		if (sum == m and tail-head < ans) {ans=tail-head;ansh=head;anst=tail;}
		
		tail++;
	}
	cout<<ansh<<" "<<anst-1;
	return 0;
}	







