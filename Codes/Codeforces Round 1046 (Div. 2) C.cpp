// Problem: C. Against the Difference
// Contest: Codeforces - Codeforces Round 1046 (Div. 2)
// URL: https://codeforces.com/contest/2136/problem/C
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

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	vector idx(n+1,vector<int>(0));
	vector<int> dp(n+1);//以i结尾的max
	for(int i=1;i<=n;i++) {
		idx[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++) {
		int pos=ranges::lower_bound(idx[a[i]],i)-idx[a[i]].begin();
		if (pos+1 < a[i]) dp[i]=dp[i-1];
		else dp[i]=max(dp[idx[a[i]][pos-a[i]+1]-1]+a[i],dp[i-1]);
	}
	
	cout<<dp[n]<<'\n';
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









