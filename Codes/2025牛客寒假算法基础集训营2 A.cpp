// Problem: 一起奏响历史之音！
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95334/A
// Memory Limit: 2048 MB
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
	vector<int> a(7);
	for(int i=0;i<7;i++) cin>>a[i];
	for(int i=0;i<7;i++) {
		if (a[i] == 4 or a[i] == 7) {cout<<"NO\n";return;}
	}
	cout<<"YES\n";
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









