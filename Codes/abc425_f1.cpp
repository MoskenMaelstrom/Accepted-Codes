// Problem: F - Inserting Process
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Autumn (AtCoder Beginner Contest 425)
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_f
// Memory Limit: 1024 MB
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

const int p=998244353;
int C[5001][5001];
void solve()
{
	//C[n][m]=C[n-1][m-1]+C[n-1][m]
	for(int i=0;i<=5000;i++) {
		C[i][0]=1;
		for(int j=1;j<=i;j++) {
			C[i][j]=C[i-1][j-1]+C[i-1][j]%p;
		}
	}
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=" "+s;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) {
		char c;
		cin>>c;
		a[i]=c-'a';
	}
	
	vector dp(n+2,vector<int>(n+2));
	for(int i=1;i<=n+1;i++) {
		dp[i][i-1]=1;
	}
	for(int len=1;len<=n;len++) {
		for(int i=1;i<=n-len+1;i++) {
			int j=i+len-1;
			for(int k=i;k<=j;k++) {
				if (s[k] == s[i-1]) continue;
				dp[i][j]+=dp[i][k-1]*dp[k+1][j]%p*C[j-i][k-i]%p;
				dp[i][j]%=p;
			}
		}
	}
	cout<<dp[1][n];
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









