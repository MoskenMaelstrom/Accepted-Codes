// Problem: D - Substr Swap
// Contest: AtCoder - AtCoder Beginner Contest 419
// URL: https://atcoder.jp/contests/abc419/tasks/abc419_d
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
	int n,m;
	cin>>n>>m;
	string s1,s2;
	cin>>s1>>s2;
	s1=" "+s1;
	s2=" "+s2;
	vector<int> a(n+2);
	
	while (m--) {
		int l,r;
		cin>>l>>r;
		a[l]++;
		a[r+1]--;
	}
	
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	for(int i=1;i<=n;i++) {
		if (a[i]%2) cout<<s2[i];
		else cout<<s1[i]; 
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









