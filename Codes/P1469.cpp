// Problem: 
//     P1469 找筷子
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1469
// Memory Limit: 4 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,a,ans=0;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a;
		ans^=a;
	}
	cout<<ans;
	return 0;
}