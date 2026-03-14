// Problem: D. How many trees?
// Contest: Codeforces - Codeforces Beta Round 9 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/9/D
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int dp[40][40];
void solve()
{
	int n,h;
	cin>>n>>h;
	for(int i=0;i<=n;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			for(int k=0;k<j;k++) {
				dp[j][i]+=dp[k][i-1]*dp[j-k-1][i-1];
			}
		}
	}
	cout<<dp[n][n]-dp[n][h-1];
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







