// Problem: 
//     P3811 【模板】模意义下的乘法逆元
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3811
// Memory Limit: 125 MB
// Time Limit: 500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int d,x,y,px,py;//d为最大公因数; (x,y)是一组特解
void exgcd(int a,int b)//a,b当前的两个过程数字,不用考虑入参大小
{
	if (b != 0) {
		exgcd(b,a%b);
		px=x;//px更新为下一次的x
		py=y;//py更新为下一次的y
		x=py;//求解的这次的x就是下次的y
		y=px-py*(a/b);
	} else {
		d=a;
		x=1;
		y=0;
	}
}

signed main()
{
	int n,p;
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		exgcd(i,p);
		cout<<(x%p+p)%p<<endl;
	}
	return 0;
}