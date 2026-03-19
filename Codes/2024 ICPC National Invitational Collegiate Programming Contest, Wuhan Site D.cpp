// Problem: D. ICPC
// Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
// URL: https://codeforces.com/gym/105143/problem/D
// Memory Limit: 1024 MB
// Time Limit: 6000 ms
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	vector dp(n,vector<int>(2*n+1));
	for(int i=0;i<n;i++) {
		int l=0,r=0;
		for(int j=0;j<=2*n;j++) {
			if (j <= i) l+=a[i-j];
			if (i+j < n) r+=a[i+j];
			dp[i][j]+=max(l,r);
		}
	}
	
	for(int j=1;j<=2*n;j++) {
		for(int i=0;i<n;i++) {
			if (i != n-1) dp[i][j]=max(dp[i][j],dp[i+1][j-1]);
			if (i != 0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++) {
		int res=0;
		for(int j=1;j<=2*n;j++) {
			res^=j*dp[i][j];
		}
		res+=i+1;
		ans^=res;
	}
	cout<<ans<<"\n";
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







