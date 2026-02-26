// Problem: A. Treasure Hunt
// Contest: Codeforces - Codeforces Round 1012 (Div. 2)
// URL: https://codeforces.com/contest/2090/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int x,y,a;
	cin>>x>>y>>a;
	if (a%(x+y) < x) cout<<"NO\n";
	else cout<<"YES\n";
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









