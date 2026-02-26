// Problem: 
//     P1100 高低位交换
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1100
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n;
	cin>>n;
	cout<<(((n&0x0000ffff)<<16) + ((n&0xffff0000)>>16));
	return 0;
}