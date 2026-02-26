// Problem: G. Mukhammadali and the Smooth Array
// Contest: Codeforces - Codeforces Round 1062 (Div. 4)
// URL: https://codeforces.com/contest/2167/problem/G
// Memory Limit: 256 MB
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

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1),w(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>w[i];
	int sum=0;
	for(int i=1;i<=n;i++) sum+=w[i];
	
	vector<int> dp(n+1,0);
	for (int i=1;i<=n;i++) {
		dp[i]=w[i];
	    for (int j=1;j<i;j++) {
	        if (a[j] <= a[i]) {
	            dp[i]=max(dp[i],dp[j]+w[i]);
	        }
	    }
	}
	
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<sum-ans<<"\n";
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









