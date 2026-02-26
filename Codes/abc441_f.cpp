// Problem: F - Must Buy
// Contest: AtCoder - AtCoder Beginner Contest 441 (Promotion of Engineer Guild Fes)
// URL: https://atcoder.jp/contests/abc441/tasks/abc441_f
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> cost(n+1),val(n+1);
	for(int i=1;i<=n;i++) cin>>cost[i]>>val[i];
	
	vector f(n+2,vector<int>(m+1));
	for(int i=n;i>0;i--) {
		for(int j=m;j>0;j--) {
			f[i][j]=f[i+1][j];
			if (j >= cost[i]) f[i][j]=max(f[i+1][j],f[i+1][j-cost[i]]+val[i]);
		}
	}
	
	vector g(n+2,vector<int>(m+1));
	for(int i=1;i<=n;i++) {
		for(int j=m;j>0;j--) {
			g[i][j]=g[i-1][j];
			if (j >= cost[i]) g[i][j]=max(g[i-1][j],g[i-1][j-cost[i]]+val[i]);
		}
	}
	
	int res=f[1][m];
	for(int i=1;i<=n;i++) {
		int v1=0,v2=0;
		for(int j=m;j>=0;j--) {
			if (j-cost[i] >= 0) v1=max(v1,g[i-1][j-cost[i]]+f[i+1][m-j]+val[i]);
			v2=max(v2,g[i-1][j]+f[i+1][m-j]);
		}
		if (v1 == res and v2 != res) cout<<'A';
		else if (v1 == res and v2 == res) cout<<'B';
		else cout<<'C';
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







