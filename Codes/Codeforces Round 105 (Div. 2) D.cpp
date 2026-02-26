// Problem: D. Bag of mice
// Contest: Codeforces - Codeforces Round 105 (Div. 2)
// URL: https://codeforces.com/problemset/problem/148/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int w,b;
	cin>>w>>b;
	vector dp(w+1,vector<double>(b+1));
	for(int i=1;i<=w;i++) dp[i][0]=1;
	for(int j=1;j<=b;j++) dp[0][j]=0;
	for(int i=1;i<=w;i++) {
		for(int j=1;j<=b;j++) {
			dp[i][j]+=(double)i/(i+j);
			if (j >= 3) dp[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*dp[i][j-3];
			if (j >= 2) dp[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*dp[i-1][j-2];
		}
	}
	cout<<fixed<<setprecision(10)<<dp[w][b];
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







