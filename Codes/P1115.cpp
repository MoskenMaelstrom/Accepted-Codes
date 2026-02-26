// Problem: 
//     P1115 最大子段和
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1115
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int n,a,f=0,ans=0x80000000;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a;
		f=max(f+a,a);
		ans=max(ans,f);
	}
	cout<<ans;
	return 0;
}







