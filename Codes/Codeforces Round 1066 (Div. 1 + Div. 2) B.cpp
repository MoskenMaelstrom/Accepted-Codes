// Problem: B. Expansion Plan 2
// Contest: Codeforces - Codeforces Round 1066 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2157/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,x,y;
	cin>>n>>x>>y;
	string s;
	cin>>s;
	int c4=ranges::count(s,'4');
	int c8=ranges::count(s,'8');
	
	x=abs(x),y=abs(y);
	x=max(0ll,x-c8);	
	y=max(0ll,y-c8);
	if (x+y <= c4) cout<<"YES\n";
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







