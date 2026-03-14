// Problem: B. Checkout Assistant
// Contest: Codeforces - Codeforces Beta Round 19
// URL: https://codeforces.com/problemset/problem/19/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	vector<int> t(n+1),c(n+1);
	int T=n;
	for(int i=1;i<=n;i++) {
		cin>>t[i]>>c[i];
		t[i]++;
		T=max(T,t[i]);
	}
	T<<=1;
	
	vector<int> dp(T+1,inf);
	dp[0]=0;
	for(int i=1;i<=n;i++) {
		for(int j=T;j>=t[i];j--) {
			dp[j]=min(dp[j],dp[j-t[i]]+c[i]);
		}
	}
	cout<<*min_element(dp.begin()+n,dp.begin()+T+1);
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







