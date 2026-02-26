// Problem: 
//     P5019 [NOIP2018 提高组] 铺设道路
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5019
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int n,ans=0;
	cin>>n;
	vector<int> a(n+5);
	rep(i,n)cin>>a[i];
	for(int i=1;i<n;i++)
		if(a[i]>a[i-1])ans+=a[i]-a[i-1];
	cout<<ans+a[0];
	return 0;
}





