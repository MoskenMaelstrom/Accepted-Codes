// Problem: L - Dice Sum
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/L
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int p=998244353;
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector dp(n+1,vector<int>(k+1000));
	dp[0][0]=1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<=k;j++) {	
			for(int l=1;l<=m;l++) {
				dp[i+1][j+l]+=dp[i][j],dp[i+1][j+l]%=p;
			}
		}
	}
	int ans=0;
	for(int j=0;j<=k;j++) ans+=dp[n][j],ans%=p;
	cout<<ans;
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









