// Problem: 
//     P1082 [NOIP2012 提高组] 同余方程
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1082
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int x,y,px,py,d;
void exgcd(int a,int b)
{
	if (b == 0) {
		x=1;
		y=0;
		d=a;
	} else {
		exgcd(b,a%b);
		px=x;
		py=y;
		x=py;
		y=px-py*(a/b);
	}
}
signed main()
{
	int a,b;
	cin>>a>>b;
	exgcd(a,b);
	cout<<(x%b+b)%b;
	return 0;
}