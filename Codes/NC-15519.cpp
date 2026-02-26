// Problem: 是是非非
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/15519
// Memory Limit: 2 MB
// Time Limit: 15519000 ms
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int res=0;
	for(int i=0;i<n;i++) res^=a[i];
	
	while (q--) {
		int x,y;
		cin>>x>>y;
		x--;
		res^=a[x];
		a[x]=y;
		res^=a[x];
		if (res != 0) cout<<"Kan\n";
		else cout<<"Li\n";
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









