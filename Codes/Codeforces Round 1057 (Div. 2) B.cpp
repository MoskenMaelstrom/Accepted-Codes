// Problem: B. Bitwise Reversion
// Contest: Codeforces - Codeforces Round 1057 (Div. 2)
// URL: https://codeforces.com/contest/2153/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
	int a,b,c;
	cin>>a>>b>>c;
	bool ok=1;
	for(int i=0;i<32;i++) {
		int n1=((a>>i)&1);
		int n2=((b>>i)&1);
		int n3=((c>>i)&1);
		if (n1+n2+n3 == 2) ok=0;
	}
	if (ok) cout<<"YES\n";
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









