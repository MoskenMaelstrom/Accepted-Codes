// Problem: C. Annoying Game
// Contest: Codeforces - Codeforces Round 1067 (Div. 2)
// URL: https://codeforces.com/contest/2158/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	
	auto dp=a;
	dp[0]=-inf;
	for(int i=1;i<=n;i++) {
		dp[i]=max(dp[i-1]+dp[i],dp[i]);
	}
	vector<int> ans(n+1,-inf);
	for(int i=1;i<=n;i++) {
		ans[i]=max({ans[i-1]+a[i],dp[i-1]+a[i]+b[i],a[i]+b[i]});
	}
	
	if (k%2 == 0) cout<<*ranges::max_element(dp)<<"\n";
	else cout<<*ranges::max_element(ans)<<"\n";
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







