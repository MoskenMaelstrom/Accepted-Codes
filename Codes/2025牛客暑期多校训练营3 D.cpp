// Problem: Distant Control
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108300/D
// Memory Limit: 1024 MB
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
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c1=0,c0=0;
	int m1=0,m0=0;
	for(int i=0;i<n;i++) {
		if (s[i] == '1') c1++,c0=0;
		else c0++,c1=0;
		m1=max(m1,c1);
		m0=max(m0,c0);
	}
	if (m1 >= m or m0 >= m+1) cout<<n<<'\n';
	else cout<<ranges::count(s,'1')<<'\n';
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









