// Problem: Forsaken City
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108304/C
// Memory Limit: 2048 MB
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
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int minn=a[n-1];
	int ans=0;
	for(int i=n-1;i>=0;i--) {
		if (a[i] < minn) minn=a[i];
		else ans=max(ans,a[i]-minn);
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









