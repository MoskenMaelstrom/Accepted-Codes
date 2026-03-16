// Problem: D. Fox And Jumping
// Contest: Codeforces - Codeforces Round 290 (Div. 2)
// URL: https://codeforces.com/problemset/problem/510/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	
	map<int,int> dp;
	dp[0]=0;
	for(int i=1;i<=n;i++) {
		map<int,int> ndp;
		for(auto [j,cost] : dp) {
			int g=gcd(j,b[i]);
			if (ndp.count(g) == 0 or a[i]+cost < ndp[g]) ndp[g]=a[i]+cost;
		}
		for(auto [j,cost] : ndp) {
			if (dp.count(j) == 0 or cost < dp[j]) dp[j]=ndp[j];
		}
	}
	if (dp.count(1) == 0) cout<<"-1\n";
	else cout<<dp[1];
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







