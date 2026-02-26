// Problem: B. Niko's Tactical Cards
// Contest: Codeforces - Codeforces Round 1068 (Div. 2)
// URL: https://codeforces.com/contest/2173/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	int dp0=0,dp1=0;
	for(int i=0;i<n;i++) {
		int p0=max(dp0-a[i],dp1+b[i]);
		int p1=max(dp0-b[i],dp1+a[i]);
		dp0=p0;
		dp1=p1;
	}
	cout<<dp0<<"\n";
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







