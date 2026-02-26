// Problem: B. Permutation
// Contest: Codeforces - Codeforces Round 209 (Div. 2)
// URL: https://codeforces.com/problemset/problem/359/B
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
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	n<<=1;
	cout<<k+1<<" ";
	for(int i=1;i<=n;i++) {
		if (i != k+1) cout<<i<<" ";
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









