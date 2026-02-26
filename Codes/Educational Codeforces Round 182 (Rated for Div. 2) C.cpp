// Problem: C. Non-Descending Arrays
// Contest: Codeforces - Educational Codeforces Round 182 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2144/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	vector<int> dp(n);
	dp[0]=2;
	for(int i=1;i<n;i++) {
		int cnt=0;
		if (a[i] >= a[i-1] and b[i] >= b[i-1]) cnt++;
		if (a[i] >= b[i-1] and b[i] >= a[i-1]) cnt++;
		dp[i]=dp[i-1]*cnt;
		dp[i]%=p;
	}
	cout<<dp[n-1]<<"\n";
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









