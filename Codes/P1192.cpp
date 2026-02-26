// Problem: P1192 台阶问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1192
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e5+3;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	a[0]=1;
	for(int i=1;i<=n;i++) {
		int sum=0;
		for(int j=1;j<=k;j++) {
			sum+=a[i-j];
			sum%=MOD;
			if (i-j == 0) break;
		}
		a[i]=sum;
	}
	cout<<a[n];
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









