// Problem: For the Treasury!
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108301/F
// Memory Limit: 2048 MB
// Time Limit: 4000 ms
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
	int n,k,c;
	cin>>n>>k>>c;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		a[i]-=c*i;
	}
	ranges::sort(a);
	int ans=0;
	for(int i=n-1;i>n-1-k;i--) {
		ans+=a[i]+c*(n-1-i);
	}
	cout<<ans;
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









