// Problem: D. Flood Fill
// Contest: Codeforces - Codeforces Round 538 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1114/D
// Memory Limit: 256 MB
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
	vector<int> a;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		if (!a.empty() and x == a.back()) continue;
		a.push_back(x);
	}
	n=a.size();
	vector dp(n,vector<int>(n,-1));
	function<int(int,int)> dfs=[&](int l,int r) -> int {
		if (l >= r) return 0;
		if (dp[l][r] != -1) return dp[l][r];
		if (a[l] == a[r]) return dp[l][r]=dfs(l+1,r-1)+1;
		else return dp[l][r]=min({dfs(l,r-1)+1,dfs(l+1,r)+1,dfs(l+1,r-1)+2});
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







