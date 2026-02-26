// Problem: A. Souvlaki VS. Kalamaki
// Contest: Codeforces - Codeforces Round 1063 (Div. 2)
// URL: https://codeforces.com/contest/2163/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	
	int ok=1;
	for(int i=0;i<n-1;i++) {
		if (i%2 == 1 and a[i] != a[i+1]) ok=0;
	}
	if (ok) cout<<"YES\n";
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







