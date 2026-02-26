// Problem: E. Three Strings
// Contest: Codeforces - Codeforces Round 991 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2050/E
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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

void solve()
{
	string a,b,c;
	cin>>a>>b>>c;
	
	int n=a.size();
	int m=b.size();
	vector dp(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++) {
		dp[i][0]=dp[i-1][0]+(a[i-1] == c[i-1]);
	}
	for(int j=1;j<=m;j++) {
		dp[0][j]=dp[0][j-1]+(b[j-1] == c[j-1]);
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			dp[i][j]=max(dp[i-1][j]+(a[i-1] == c[j+i-1]),
						 dp[i][j-1]+(b[j-1] == c[j+i-1]));
		}
	}
	cout<<n+m-dp[n][m]<<"\n";
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









