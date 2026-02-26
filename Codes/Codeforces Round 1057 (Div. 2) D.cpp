// Problem: D. Not Alone
// Contest: Codeforces - Codeforces Round 1057 (Div. 2)
// URL: https://codeforces.com/contest/2153/problem/D
// Memory Limit: 256 MB
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
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	vector<int> dp(n+1,inf);
	dp[0]=0;
	for(int i=2;i<=n;i++) {
		int m1=min({a[i],a[i-1],a[i-2]});
		int m3=max({a[i],a[i-1],a[i-2]});
		if (i>=3 and i-3 != 1) dp[i]=min(dp[i],dp[i-3]+m3-m1);
		if (i-2 != 1) dp[i]=min(dp[i],dp[i-2]+abs(a[i]-a[i-1]));
	}
	int res=dp[n];
	
	vector b=a;
	b.push_back(a[1]);
	b.push_back(a[2]);
	
	for(int i=2;i<=n+1;i++) a[i-1]=b[i];
	dp.assign(n+1,inf);
	dp[0]=0;
	for(int i=2;i<=n;i++) {
		int m1=min({a[i],a[i-1],a[i-2]});
		int m3=max({a[i],a[i-1],a[i-2]});
		if (i>=3 and i-3 != 1) dp[i]=min(dp[i],dp[i-3]+m3-m1);
		if (i-2 != 1) dp[i]=min(dp[i],dp[i-2]+abs(a[i]-a[i-1]));
	}
	res=min(res,dp[n]);
	
	
	for(int i=3;i<=n+2;i++) a[i-2]=b[i];
	dp.assign(n+1,inf);
	dp[0]=0;
	for(int i=2;i<=n;i++) {
		int m1=min({a[i],a[i-1],a[i-2]});
		int m3=max({a[i],a[i-1],a[i-2]});
		if (i>=3 and i-3 != 1) dp[i]=min(dp[i],dp[i-3]+m3-m1);
		if (i-2 != 1) dp[i]=min(dp[i],dp[i-2]+abs(a[i]-a[i-1]));
	}
	res=min(res,dp[n]);
	
	
	cout<<res<<"\n";
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









