// Problem: C. Beautiful Sequence
// Contest: Codeforces - Educational Codeforces Round 174 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2069/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
#define int long long
using namespace std;

const int p=998244353;


void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &e1 : a) cin>>e1;
	vector<int> dp(n);
	int cnt1=0;
	if (a[0] == 1) cnt1++;
	for(int i=1;i<n;i++) {
		if (a[i] == 1) {cnt1++;dp[i]=dp[i-1];}
		else if (a[i] == 2) dp[i]+=2*dp[i-1]+cnt1;
		else dp[i]=dp[i-1];
		dp[i]%=p;
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		if (a[i] == 3) {
			ans+=dp[i];
			ans%=p;
		}
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









