// Problem: E. Fish
// Contest: Codeforces - Codeforces Beta Round 16 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/16/E
// Memory Limit: 128 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector a(n,vector<double>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}
	
	vector<double> dp(1<<n);
	dp[(1<<n)-1]=1;
	for(int s=(1<<n)-1;s>0;s--) {
		int k=__builtin_popcount(s);
		k=k*(k-1)/2;
		for(int i=0;i<n;i++) {
			if ((s>>i)&1) {
				for(int j=i+1;j<n;j++) {
					if ((s>>j)&1) {
						dp[s^(1<<j)]+=dp[s]*a[i][j]/k;
						dp[s^(1<<i)]+=dp[s]*a[j][i]/k;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++) cout<<fixed<<setprecision(10)<<dp[1<<i]<<" ";
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







