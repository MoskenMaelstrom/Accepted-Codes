// Problem: B. Cake Collection
// Contest: Codeforces - Codeforces Round 1048 (Div. 2)
// URL: https://codeforces.com/contest/2139/problem/B
// Memory Limit: 512 MB
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
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);

	for(int i=n-1;i>=0;i--) {
		a[i]*=m;
		m--;
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		if (a[i] > 0) ans+=a[i];
	}
	cout<<ans<<'\n';
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









