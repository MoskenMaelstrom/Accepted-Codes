// Problem: Constructive
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/K
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	if (n == 1) {
		cout<<"YES\n";
		cout<<"1\n";
	}
	else if (n == 3) {
		cout<<"YES\n";
		cout<<"1 2 3\n";
	}
	else cout<<"NO\n";
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







