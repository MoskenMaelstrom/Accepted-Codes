// Problem: P2822 [NOIP 2016 提高组] 组合数问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2822
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t,k;
	cin>>t>>k;
	
	vector a(2001,vector<int>(2001,1));
	for(int i=1;i<=2000;i++)
		for(int j=1;j<=i-1;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j],a[i][j]%=k;
	
	vector b(2001,vector<int>(2001,0));
	//b[i][j]表示第i行前j个数字中 合法的数字个数
	for(int i=0;i<=2000;i++) {
		int cnt=0;
		for(int j=0;j<=i;j++) {
			if (a[i][j] == 0) cnt++;
			b[i][j]=cnt;
		}
	}
	//查询
	while (t--)
	{
		int n,m;
		cin>>n>>m;
		int cnt=0;
		for(int i=0;i<=n;i++) cnt+=b[i][min(i,m)];
		
		cout<<cnt<<endl;
	}
	return 0;
}








