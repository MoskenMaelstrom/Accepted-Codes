// Problem: A. Convergence
// Contest: Codeforces - Codeforces Round 1101 (Div. 2)
// URL: https://codeforces.com/contest/2232/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	int ans=n;
	for(int i=0;i<n;i++) {
		int l=ranges::lower_bound(a,a[i])-a.begin();
		int r=a.end()-ranges::upper_bound(a,a[i]);
		ans=min(ans,max(l,r));
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







