// Problem: C. Huge Pile
// Contest: Codeforces - Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/contest/2184/problem/C
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
	int n,k;
	cin>>n>>k;
	bool ok=0;
	for(int i=0;i<=60;i++) {
		int q=n>>i;
		if (q < k and (q+1) < k) break;
		if (q == k or q+1 == k and (n&((1ll<<i)-1))) {
			cout<<i<<"\n";
			return;
		}
	}
	cout<<"-1\n";
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







