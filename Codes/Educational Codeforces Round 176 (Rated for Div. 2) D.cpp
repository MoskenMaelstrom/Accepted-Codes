// Problem: D. Equalization
// Contest: Codeforces - Educational Codeforces Round 176 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2075/problem/D
// Memory Limit: 256 MB
// Time Limit: 3500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

vector dp(64,vector<int>(64,LINF/5));

void solve()
{
	int n1,n2;
	cin>>n1>>n2;
	int ans=LINF;
	for(int i=0;i<62;i++) {
		for(int j=0;j<62;j++) {
			if (n1>>i == n2>>j) ans=min(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	dp[0][0]=0;
	for(int i=0;i<63;i++) {
		for(int j=63;j>=0;j--) {
			for(int k=63;k>=0;k--) {
				if (j-i >= 0) dp[j][k]=min(dp[j][k],dp[j-i][k]+(1ll<<i));
				if (k-i >= 0) dp[j][k]=min(dp[j][k],dp[j][k-i]+(1ll<<i));
			}
		}
	}
	
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









