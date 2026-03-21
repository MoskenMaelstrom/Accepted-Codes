// Problem: D. Serval and Rooted Tree
// Contest: Codeforces - Codeforces Round 551 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1153/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> pa(n),deg(n);
	for(int i=1;i<n;i++) {
		cin>>pa[i];
		pa[i]--;
		deg[pa[i]]++;
	}
	vector<int> siz(n),dp(n);
	for(int i=0;i<n;i++) {
		if (deg[i] == 0) siz[i]=1,dp[i]=1;
		else dp[i]=a[i] ? inf : 0;
	}
	
	for(int i=n-1;i>0;i--) {
		siz[pa[i]]+=siz[i];
		if (a[pa[i]] == 1) dp[pa[i]]=min(dp[pa[i]],dp[i]);
		else dp[pa[i]]+=dp[i];
	}
	cout<<siz[0]-dp[0]+1;
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







