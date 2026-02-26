// Problem: F. Igor and Mountain
// Contest: Codeforces - Codeforces Round 1013 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2091/F
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
	int n,m,d;
	cin>>n>>m>>d;
	vector a(n+1,vector<char>(m+1));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>a[i][j];
		}
	}
	vector dp(n+1,vector<int>(m+1));
	vector pre(n+1,vector<int>(m+1));
	
	for(int j=1;j<=m;j++) if (a[n][j] == 'X') pre[n][j]=1;
	
	int len=d-1;
	for(int i=n-1;i>=1;i--) {
		
		for(int j=1;j<=m;j++) {
			pre[i+1][j]+=pre[i+1][j-1];
			pre[i+1][j]%=p;
		}
		
		for(int j=1;j<=m;j++) {
			if (a[i+1][j] == 'X') {
				dp[i+1][j]=pre[i+1][min(j+d,m)]-pre[i+1][max(0ll,j-d-1)];
				dp[i+1][j]%=p;
			}
			dp[i+1][j]+=dp[i+1][j-1];
			dp[i+1][j]%=p;
		}
		
		for(int j=1;j<=m;j++) {
			if (a[i][j] == 'X') {
				dp[i][j]=dp[i+1][min(j+len,m)]-dp[i+1][max(0ll,j-len-1)];
				dp[i][j]%=p;
			}
		}
		
		pre[i]=dp[i];
	}
	for(int j=1;j<=m;j++) {
		pre[1][j]+=pre[1][j-1];
		pre[1][j]%=p;
	}
	for(int j=1;j<=m;j++) {
		if (a[1][j] == 'X') {
			dp[1][j]=pre[1][min(j+d,m)]-pre[1][max(0ll,j-d-1)];
			dp[1][j]%=p;
		}
	}
	
	int ans=0;
	for(int j=1;j<=m;j++) if (a[1][j] == 'X') ans+=dp[1][j],ans%=p;
	cout<<(ans+p)%p<<"\n";
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









