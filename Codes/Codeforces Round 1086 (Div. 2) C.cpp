// Problem: C. Stamina and Tasks
// Contest: Codeforces - Codeforces Round 1086 (Div. 2)
// URL: https://codeforces.com/contest/2208/problem/C
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
	vector<int> c(n),p(n);
	for(int i=0;i<n;i++) cin>>c[i]>>p[i];
	vector<double> dp(n+1);
	for(int i=n-1;i>=0;i--) {
		dp[i]=max(dp[i+1],c[i]+(double)(1-(double)p[i]/100)*dp[i+1]);
	}
	cout<<fixed<<setprecision(10)<<dp[0]<<"\n";
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







