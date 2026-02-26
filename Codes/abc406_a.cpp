// Problem: A - Not Acceptable
// Contest: AtCoder - Panasonic Programming Contest 2025（AtCoder Beginner Contest 406）
// URL: https://atcoder.jp/contests/abc406/tasks/abc406_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a == c) {
		if (b >= d) cout<<"Yes\n";
		else cout<<"No\n";
	}
	else if (a > c) cout<<"Yes\n";
	else cout<<"No\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









