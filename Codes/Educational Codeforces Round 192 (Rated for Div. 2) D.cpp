// Problem: D. Two Digit Strings
// Contest: Codeforces - Educational Codeforces Round 192 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2242/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size();
	int m=s2.size();
	vector<int> a(n+1),b(m+1);
	for(int i=1;i<=n;i++) {
		(a[i]=a[i-1]+s1[i-1]-'0')%=10;
	}
	for(int i=1;i<=m;i++) {
		(b[i]=b[i-1]+s2[i-1]-'0')%=10;
	}
	if (a[n] != b[m]) {cout<<"-1\n";return;}
	
	vector dp(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if (a[i] == b[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][m]<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







