// Problem: B. Zuma
// Contest: Codeforces - Codeforces Round 336 (Div. 1)
// URL: https://codeforces.com/problemset/problem/607/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
	vector dp(n,vector<int>(n,-1));
	
	function<int(int,int)> dfs=[&](int l,int r) -> int {
		if (l > r) return 0;
		if (l == r) return 1;
		if (dp[l][r] != -1) return dp[l][r];
		int res=1+dfs(l+1,r);
		for(int i=l+1;i<=r;i++) {
			if (a[l] == a[i]) {
				if (i == l+1) res=min(res,1+dfs(i+1,r));
				else res=min(res,dfs(l+1,i-1)+dfs(i+1,r));
			}
		}
		return dp[l][r]=res;
	};
	cout<<dfs(0,n-1);
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







