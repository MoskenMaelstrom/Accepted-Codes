// Problem: D. Sum of LDS
// Contest: Codeforces - Codeforces Round 1039 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2128/D
// Memory Limit: 256 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=n*(n+1)*(n+2)/6;
	for(int i=0;i<n-1;i++) {
		if (a[i] < a[i+1]) ans-=(i+1)*(n-i-1);
	}
	cout<<ans<<"\n";
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









