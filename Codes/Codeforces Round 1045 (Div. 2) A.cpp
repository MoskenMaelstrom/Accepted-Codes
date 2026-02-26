// Problem: A. Painting With Two Colors
// Contest: Codeforces - Codeforces Round 1045 (Div. 2)
// URL: https://codeforces.com/contest/2134/problem/0
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
	int n,a,b;
	cin>>n>>a>>b;
	if (a <= b) {
		if (n%2 == b%2) cout<<"YES\n";
		else cout<<"NO\n";	
	}
	else {
		if (n%2 == a%2 and a%2 == b%2) cout<<"YES\n";
		else cout<<"NO\n";
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









