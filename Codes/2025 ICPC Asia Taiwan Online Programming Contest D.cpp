// Problem: D. Palindromic Distance
// Contest: Codeforces - 2025 ICPC Asia Taiwan Online Programming Contest
// URL: https://codeforces.com/gym/106084/problem/D
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	vector dp(n,vector<int>(n,-1));
	function<int(int,int)> dfs=[&](int l,int r) -> int {
		if (l >= r) return 0;
		if (dp[l][r] != -1) return dp[l][r];
		int res=0;
		if (s[l] == s[r]) res=dfs(l+1,r-1);
		else res=min({dfs(l+1,r-1)+1,dfs(l+1,r)+1,dfs(l,r-1)+1});
		return dp[l][r]=res;
	};
	cout<<dfs(0,n-1)<<"\n";
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







