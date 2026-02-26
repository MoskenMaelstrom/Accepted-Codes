// Problem: A. Draw a Square
// Contest: Codeforces - Codeforces Round 1009 (Div. 3)
// URL: https://mirror.codeforces.com/contest/2074/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a == b and b == c and c == d) cout<<"Yes\n";
	else cout<<"No\n";
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









