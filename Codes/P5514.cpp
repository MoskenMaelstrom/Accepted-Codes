// Problem: 
//     P5514 [MtOI2019] 永夜的报应
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5514
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		int a;
		cin>>a;
		ans^=a;
	}
	cout<<ans;
	return 0;
}