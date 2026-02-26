// Problem: C - Upgrade Required
// Contest: AtCoder - AtCoder Beginner Contest 426
// URL: https://atcoder.jp/contests/abc426/tasks/abc426_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: C - Bipartize
// Contest: AtCoder - Panasonic Programming Contest 2025（AtCoder Beginner Contest 427）
// URL: https://atcoder.jp/contests/abc427/tasks/abc427_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1,1);
	int minx=1;
	while (q--) {
		int x,y;
		cin>>x>>y;
		int res=0;
		while (minx <= x) {
			res+=a[minx];
			a[y]+=a[minx];
			minx++;
		}
		cout<<res<<'\n';
	}
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









