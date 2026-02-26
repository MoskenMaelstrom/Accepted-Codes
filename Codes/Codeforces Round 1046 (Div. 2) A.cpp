// Problem: A. In the Dream
// Contest: Codeforces - Codeforces Round 1046 (Div. 2)
// URL: https://codeforces.com/contest/2136/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	c-=a,d-=b;
	
	int b1,b2,a1,a2;
	a1=min(a,b);
	a2=max(a,b);
	b1=min(c,d);
	b2=max(c,d);
	if (a1*2+2 >= a2 and b1*2+2 >= b2) cout<<"YES\n";
	else cout<<"NO\n";
	
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









