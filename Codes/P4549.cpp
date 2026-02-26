// Problem: 
//     P4549 【模板】裴蜀定理
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4549
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int n,a,ans;
	cin>>n;
	cin>>ans;
	for(int i=2;i<=n;i++) {
		cin>>a;
		a=abs(a);
		ans=gcd(a,ans);
	}
	cout<<ans;
	return 0;
}