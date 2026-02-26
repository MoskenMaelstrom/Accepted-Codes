// Problem: D. Taiga's Carry Chains
// Contest: Codeforces - Codeforces Round 1068 (Div. 2)
// URL: https://codeforces.com/contest/2173/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(40);
	for(int i=1;i<=39;i++) {
		a[i]=((n>>(i-1))&1);
	}
	vector dp(41,vector<int>(41,-1));
	dp[0][0]=0;
	for(int i=0;i<=39;i++) {
		for(int j=0;j<=i;j++) {
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			int cnt=0;
			for(int k=i+1;k<=39;k++) {
				if (a[k] == 0) {
					cnt++;
					dp[k][j+cnt]=max(dp[k][j+cnt],dp[i][j]+k-i-1);
				}
			}
		}
	}
	
	int ans=0;
	for(int j=0;j<=39 and j<=k;j++) {
		ans=max(ans,dp[39][j]+k-j);
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







