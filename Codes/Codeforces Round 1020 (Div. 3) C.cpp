// Problem: C. Cherry Bomb
// Contest: Codeforces - Codeforces Round 1020 (Div. 3)
// URL: https://codeforces.com/contest/2106/problem/C
// Memory Limit: 256 MB
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n),b(n);
	int l=0,r=2*k;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		l=max(l,a[i]);
		r=min(r,a[i]+k);
	}
	for(int i=0;i<n;i++) {
		cin>>b[i];
		if (b[i] != -1) {
			l=max(l,a[i]+b[i]);
			r=min(r,a[i]+b[i]);
		}
	}
	cout<<max(0ll,r-l+1)<<endl;
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









