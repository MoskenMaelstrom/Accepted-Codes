// Problem: F. Goodbye, Banker Life
// Contest: Codeforces - Codeforces Round 1006 (Div. 3)
// URL: https://codeforces.com/contest/2072/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		cout<<(((n-1)|i) == n-1 ? k : 0)<<" \n"[i == n-1];
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









