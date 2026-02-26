// Problem: B. Mashmokh and ACM
// Contest: Codeforces - Codeforces Round 240 (Div. 1)
// URL: https://codeforces.com/problemset/problem/414/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

int p=1e9+7;
void solve()
{
	int n,k;
	cin>>n>>k;	

	vector dp(k+1,vector<int>(n+1));
	for(int i=1;i<=n;i++) dp[1][i]=1;
	for(int i=2;i<=k;i++)
		for(int j=1;j<=n;j++)
				for(int k=1;k*j<=n;k++)
					dp[i][j]=(dp[i][j]+dp[i-1][k*j])%p;
	
	int ans=0;
	for(int i=1;i<=n;i++) ans=(ans+dp[k][i])%p;
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









