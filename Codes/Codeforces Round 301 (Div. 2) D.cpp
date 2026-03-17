// Problem: D. Bad Luck Island
// Contest: Codeforces - Codeforces Round 301 (Div. 2)
// URL: https://codeforces.com/problemset/problem/540/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

double dp[101][101][101];
void solve()
{
	int r,s,p;
	cin>>r>>s>>p;
	for(int i=1;i<=100;i++) {
		for(int j=1;j<=100;j++) {
			dp[i][j][0]=1;
			for(int k=1;k<=100;k++) {
				dp[i][j][k]=(i*j*dp[i][j-1][k]+j*k*dp[i][j][k-1]+i*k*dp[i-1][j][k])/(i*j+j*k+k*i);
			}
		}
	}
	cout<<fixed<<setprecision(12)<<dp[r][s][p]<<" "<<dp[s][p][r]<<" "<<dp[p][r][s];
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







