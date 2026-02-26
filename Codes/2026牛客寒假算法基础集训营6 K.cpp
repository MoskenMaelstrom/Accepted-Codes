// Problem: 小L的游戏1
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120566/K
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int m,n,z;
	cin>>m>>n>>z;
	z%=m+n;
	if (z == 0 or z > m) cout<<1;
	else cout<<0;
	
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







