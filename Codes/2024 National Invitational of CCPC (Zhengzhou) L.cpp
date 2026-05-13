// Problem: L. Toxel 与 PCPC II
// Contest: Codeforces - 2024 National Invitational of CCPC (Zhengzhou), 2024 CCPC Henan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105158/problem/L
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int Pow(int base,int exp) {
	int res=1;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base;
		base*=base;
	}
	return res;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(m+1);
	for(int i=1;i<=m;i++) cin>>a[i];
	
	vector<int> dp(m+1,1e18);
	dp[0]=0;
	for(int i=1;i<=m;i++) {
		for(int j=i-1;j>=max(0ll,i-100);j--) {
			dp[i]=min(dp[i],dp[j]+a[i]+Pow(i-j,4));
		}
	}
	cout<<dp[m];
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







