// Problem: B. Tab Closing
// Contest: Codeforces - Codeforces Round 1064 (Div. 2)
// URL: https://codeforces.com/contest/2166/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int a,b,n;
	cin>>a>>b>>n;
	
	int c1=a/b;
	if (n <= c1 or b >= a) cout<<"1\n";
	else {
		if (c1 >= n) cout<<"1\n";
		else cout<<"2\n";
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







