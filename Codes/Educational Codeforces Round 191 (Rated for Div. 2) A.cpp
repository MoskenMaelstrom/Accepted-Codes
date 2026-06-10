// Problem: A. AI Project Development
// Contest: Codeforces - Educational Codeforces Round 191 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2233/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,x,y,z;
	cin>>n>>x>>y>>z;
	int ans=(n+x+y-1)/(x+y);
	if (x*z >= n) ans=min(ans,(n+x-1)/x);
	else ans=min(ans,(n-x*z+x+10*y-1)/(x+10*y)+z);
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







