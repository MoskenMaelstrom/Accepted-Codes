// Problem: 
//     P1029 [NOIP2001 普及组] 最大公约数和最小公倍数问题
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1029
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=n;i<=m;i++) {
		if ((n*m)%i != 0) continue;
		if (lcm(i,(n*m)/i) == m and gcd(i,(n*m)/i) == n) ans++;
	}
	cout<<ans;
	return 0;
}