// Problem: 
//     P3374 【模板】树状数组 1
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3374
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int lowbit(int x) {return x & (-x);}

int a[N],b[N];
int	n,m;
//a数组存原数据
//b数组存树状数组

void add(int x,int k)	//在x位置加上k，即将x位置即其父节点递归性加k
{
	for(int i=x;i<=n;i+=lowbit(i)) b[i]+=k;
}

int sum(int x)	//查询x的前缀和
{
	int res=0;
	for(int i=x;i;i-=lowbit(i)) res+=b[i];
	return res;
}

signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		add(i,a[i]);
	}
	for(int i=1;i<=m;i++) {
		int F,x,y;
		cin>>F>>x>>y;
		//第x数加上y
		if (F == 1) add(x,y);
		else cout<<sum(y)-sum(x-1)<<endl;
	}
	return 0;
}








