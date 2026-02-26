// Problem: P3811 【模板】模意义下的乘法逆元
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3811
// Memory Limit: 125 MB
// Time Limit: 500000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,p;
	cin>>n>>p;
	int MOD=p;
	vector<int> inv(n+1);
	inv[1]=1;
	for(int i=2;i<=n;i++) {
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
	}
	for(int i=1;i<=n;i++) printf("%d\n",inv[i]);
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









