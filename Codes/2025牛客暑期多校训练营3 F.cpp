// Problem: Flower
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108300/F
// Memory Limit: 1024 MB
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
	int n,a,b;
	cin>>n>>a>>b;
	int m=n%(a+b);
	if (n <= a) cout<<"Sayonara\n";
	else if (m == 0) cout<<"0\n";
	else if (m <= a) cout<<m<<'\n';
	else cout<<"0\n";
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









