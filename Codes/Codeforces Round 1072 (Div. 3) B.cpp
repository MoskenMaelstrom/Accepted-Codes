// Problem: B. Hourglass
// Contest: Codeforces - Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/contest/2184/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int s,k,m;
	cin>>s>>k>>m;
	int t=m%k;
	if (s <= k) {
		cout<<max(0ll,s-t)<<"\n";
	}
	else {
		if (m/k%2) cout<<max(0ll,k-t)<<"\n";
		else cout<<max(0ll,s-t)<<"\n";
	}
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







