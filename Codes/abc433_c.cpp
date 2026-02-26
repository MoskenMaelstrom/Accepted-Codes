// Problem: C - 1122 Substring 2
// Contest: AtCoder - AtCoder Beginner Contest 433
// URL: https://atcoder.jp/contests/abc433/tasks/abc433_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	
	vector<int> dp(n);
	dp[n-1]=n;
	for(int i=n-2;i>=0;i--) {
		if (s[i] == s[i+1]) dp[i]=dp[i+1];
		else dp[i]=i+1;
	}
	
	int cnt=0;
	for(int l=0;l<n;l++) {
		if (dp[l]-l <= dp[dp[l]]-dp[l] and s[l]+1 == s[dp[l]]) cnt++;
	}
	cout<<cnt;
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







