// Problem: P1216 [IOI 1994] 数字三角形 Number Triangles
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1216
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector a(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>a[i][j];
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++)
			a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
	cout<<a[1][1];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









