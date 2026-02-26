// Problem: C - Rotate and Sum Query
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Autumn (AtCoder Beginner Contest 425)
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_c
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
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) a.push_back(a[i]);
	for(int i=1;i<=2*n;i++) a[i]+=a[i-1];
	
	int d=0;
	while (q--) {
		int o;
		cin>>o;
		if (o == 1) {
			int t;
			cin>>t;
			d+=t;
			d%=n;
		}
		else {
			int l,r;
			cin>>l>>r;
			l+=d,r+=d;
			cout<<a[r]-a[l-1]<<'\n';
		}
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









