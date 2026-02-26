// Problem: 
//     P5724 【深基4.习5】求极差 / 最大跨度值
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5724
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int t,a,maxa=-1,mina=1001;
	cin>>t;
	while (t--) {
		cin>>a;
		if (a>maxa) maxa=a;
		if (a<mina) mina=a;
	}
	cout<<maxa-mina;
	return 0;
}