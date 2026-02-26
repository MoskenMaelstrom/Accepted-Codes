// Problem: D. Jon and Orbs
// Contest: Codeforces - Divide by Zero 2017 and Codeforces Round 399 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/768/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const double eps=1e-7;
void solve()
{
	int k,q;
	cin>>k>>q;//p=1~2000
	// dp[i][j]=dp[i-1][j]*j/k+dp[i-1][j-1]*(k-j+1)/k;
	
	vector<double> dp(k+1);
	dp[0]=1;
	int f=0;
	vector<int> ans(1001);
	for(int i=1;f<=1000;i++) {
		for(int j=k;j>0;j--) {
			dp[j]=(double)dp[j]*j/k+(double)dp[j-1]*(k-j+1)/k;
		}
		while (dp[k] >= (f-eps)/2000 and f <= 1000) {
			ans[f]=i;
			f++;
		}
		dp[0]=0;
	}
	
	while (q--) {
		int p;
		cin>>p;
		cout<<ans[p]<<"\n";
	}
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







