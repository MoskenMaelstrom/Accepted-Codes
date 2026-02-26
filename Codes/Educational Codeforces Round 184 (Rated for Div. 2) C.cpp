// Problem: C. Range Operation
// Contest: Codeforces - Educational Codeforces Round 184 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2169/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<int> d(n+1);
	int sta=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sta+=a[i];
		d[i]=2*i-a[i];
	}
	
	int ans=sta;
	auto dp=d;
	for(int i=2;i<=n;i++) {
		dp[i]+=max(0ll,dp[i-1]);
	}
	
	for(int i=1;i<=n;i++) ans=max(dp[i]+sta,ans);
	cout<<ans<<'\n';
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







