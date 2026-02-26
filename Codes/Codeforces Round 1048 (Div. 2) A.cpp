// Problem: A. Maple and Multiplication
// Contest: Codeforces - Codeforces Round 1048 (Div. 2)
// URL: https://codeforces.com/contest/2139/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int a,b;
	cin>>a>>b;
	if (a == b) cout<<"0\n";
	else if (a%b == 0 or b%a == 0) cout<<"1\n";
	else cout<<"2\n";
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










