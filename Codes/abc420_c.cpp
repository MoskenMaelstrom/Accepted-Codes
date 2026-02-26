// Problem: C - Sum of Min Query
// Contest: AtCoder - AtCoder Beginner Contest 420
// URL: https://atcoder.jp/contests/abc420/tasks/abc420_c
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
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	int sum=0;
	for(int i=0;i<n;i++) sum+=min(a[i],b[i]);
	while (q--) {
		char c;
		int i,v;
		cin>>c>>i>>v;
		i--;
		if (c == 'A') {
			sum-=min(a[i],b[i]);
			a[i]=v;
			sum+=min(a[i],b[i]);
		}
		else {
			sum-=min(a[i],b[i]);
			b[i]=v;
			sum+=min(a[i],b[i]);
		}
		cout<<sum<<"\n";
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









