// Problem: K. Welfare
// Contest: Codeforces - The 13th Shaanxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105891/problem/K
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
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	if (x <= y) {
		cout<<y*(n+m)<<"\n";
		return;
	}
	if (n+m == 0) {
		cout<<0<<"\n";
		return;
	}
	if (n == 0) {
		if (x > y) cout<<x<<"\n";
		else cout<<y*m<<"\n";
		return;
	}
	if (m == 0) {
		cout<<x+y*(n-1)<<"\n";
		return;
	}
	if (y == 0) {
		cout<<x<<"\n";
		return;
	}
	if (x == 0) {
		cout<<y*(n+m)<<"\n";
		return;
	}
	int ans=x+n*y;
	int w=(x-1)/y;
	if (w <= n) ans=max(ans,x+(n-w+m)*y);
	cout<<ans<<"\n";
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







