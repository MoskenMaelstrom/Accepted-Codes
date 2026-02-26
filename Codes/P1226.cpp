// Problem: 
//     P1226 【模板】快速幂
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1226
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int a,b,p;
	int r=1;
	cin>>a>>b>>p;
	int a1=a;
	int b1=b;
	while (b != 0) {
		if ((b&1) == 1) r*=a;
		a=a*a;
		a%=p;
		b>>=1;
		r%=p;
	}
	cout<<a1<<"^"<<b1<<" mod "<<p<<"="<<r;
	return 0;
}