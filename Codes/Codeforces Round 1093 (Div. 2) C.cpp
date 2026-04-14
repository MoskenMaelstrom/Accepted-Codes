// Problem: C. Grid L
// Contest: Codeforces - Codeforces Round 1093 (Div. 2)
// URL: https://codeforces.com/contest/2220/problem/C
// Memory Limit: 256 MB
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
	int p,q;
	cin>>p>>q;
	int k=p+q*2;
	k=2*k+1;
	if (k < 9 or k%2 == 0) {
		cout<<"-1\n";
		return;
	}
	for(int i=2;i<=k/i;i++) {
		if (k%i) continue;
		if (i%2 and k/i%2) {
			int n=(i-1)/2;
			int m=(k/i-1)/2;
			if (abs(n-m) <= p) {
				cout<<n<<" "<<m<<"\n";
				return;
			}
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







