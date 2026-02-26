// Problem: O - Jumping Takahashi
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/O
// Memory Limit: 1024 MB
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
	int n,k;
	cin>>n>>k;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) {
		cin>>a[i]>>b[i];
	}
	vector<int> pre(k+1),dp(k+1);
	pre[0]=1;
	
	for(int i=0;i<n;i++) {
		for(int j=k;j>=0;j--) {
			if (j >= a[i]) dp[j]|=pre[j-a[i]];
			if (j >= b[i]) dp[j]|=pre[j-b[i]];
		}
		pre=dp;
		fill(dp.begin(),dp.end(),0);
	}
	if (pre[k]) cout<<"Yes";
	else cout<<"No";
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









