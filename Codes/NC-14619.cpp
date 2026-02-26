// Problem: 栗酱的异或和
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/14619
// Memory Limit: 2 MB
// Time Limit: 14619000 ms
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
	m--;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	int res=0;
	for(int i=0;i<n;i++) {
		if (i == m) continue;
		res^=a[i];
	}
	
	if (a[m] > res) cout<<"Yes\n";
	else cout<<"No\n";
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









