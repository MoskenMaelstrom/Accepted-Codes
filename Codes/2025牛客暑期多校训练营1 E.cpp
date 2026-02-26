// Problem: Endless Ladders
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108298/E
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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
	int a,b;
	cin>>a>>b;
	int d=abs(a*a-b*b);
	cout<<(d-1)/2+max(0ll,d/4-1)<<'\n';
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









