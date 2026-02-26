// Problem: E - Subarray Sum Divisibility
// Contest: AtCoder - AtCoder Beginner Contest 419
// URL: https://atcoder.jp/contests/abc419/tasks/abc419_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

const int inf=1e18;
void solve()
{
	int n,m,l;
	cin>>n>>m>>l;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	vector w(l+1,vector<int>(m));
	for(int i=1;i<=l;i++) {
		for(int k=0;k<m;k++) {
			for(int j=i;j<=n;j+=l) {
				w[i][k]+=(k-a[j]+m)%m; 
			}
		}
	};
	
	vector dp(l+1,vector<int>(m,inf));
	for(int j=0;j<m;j++) dp[1][j]=w[1][j];
	for(int i=2;i<=l;i++) {
		for(int j=0;j<m;j++) {
			for(int k=0;k<m;k++) {
				dp[i][j]=min(dp[i][j],dp[i-1][k]+w[i][(j-k+m)%m]);
			}
		}
	}
	cout<<dp[l][0];
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









