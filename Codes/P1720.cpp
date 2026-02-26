// Problem: 
//     P1720 月落乌啼算钱（斐波那契数列）
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1720
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

signed main()	//1 1 2 3 5 8 13
{
	
	int n;
	cin>>n;
	if (n == 0) {cout<<"0.00";return 0;}
	long long a=1,b=1;
	for(int i=2;i<n;i++) {
		b=a+b;
		a=b-a;
	}
	cout<<b<<".00";
	return 0;
}