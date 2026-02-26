// Problem: 
//     P1024 [NOIP2001 提高组] 一元三次方程求解
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1024
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
double a,b,c,d;
double f(double x)
{
	return a*pow(x,3)+b*pow(x,2)+c*x+d;
}
signed main()
{
	cin>>a>>b>>c>>d;
	int flag=0;
	for(double i=-100;i<=100;i+=0.01){
		if(flag==0){//找第一个>=0的值
			if(f(i)>=0){
				flag=1;
				printf("%.2f ",i);
			}
		}
		else if(flag==1){
			if(f(i)<=0){
				flag=2;
				printf("%.2f ",i);
			}
		}
		else if(flag==2){
			if(f(i)>=0){
				printf("%.2f ",i);
				return 0;
			}
		}
	}
	return 0;
}








