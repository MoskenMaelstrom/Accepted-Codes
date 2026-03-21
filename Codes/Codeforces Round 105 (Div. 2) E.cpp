// Problem: E. Porcelain
// Contest: Codeforces - Codeforces Round 105 (Div. 2)
// URL: https://codeforces.com/problemset/problem/148/E
// Memory Limit: 256 MB
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
	int n,m;
	cin>>n>>m;
	vector<int> dp(m+1);
	for(int i=0;i<n;i++) {
		int len;
		cin>>len;
		vector<int> a(len+1);
		for(int j=1;j<=len;j++) cin>>a[j],a[j]+=a[j-1];
		vector<int> s(len+1);
		for(int j=0;j<len;j++) {
			for(int k=j;k<=len;k++) {
				s[len-k+j]=max(s[len-k+j],a[len]-a[k]+a[j]);
			}
		}
		
		for(int j=m;j>0;j--) {
			for(int k=min(j,len);k>0;k--) {
				dp[j]=max(dp[j],dp[j-k]+s[k]);
			}
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







