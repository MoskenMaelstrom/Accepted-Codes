// Problem: E - Sum of Subarrays
// Contest: AtCoder - AtCoder Beginner Contest 423
// URL: https://atcoder.jp/contests/abc423/tasks/abc423_e
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
	vector<int> a1(n+1),a2(n+1),a3(n+1);
	for(int i=1;i<=n;i++) {
		a1[i]=i*a[i];
		a1[i]+=a1[i-1];
		a2[i]=i*i*a[i];
		a2[i]+=a2[i-1];
		a3[i]=a[i];
		a3[i]+=a3[i-1];
	}
	
	while (q--) {
		int l,r;
		cin>>l>>r;
		cout<<(l+r)*(a1[r]-a1[l-1])-(a2[r]-a2[l-1])+(-l*r-l+r+1)*(a3[r]-a3[l-1])<<"\n";
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









