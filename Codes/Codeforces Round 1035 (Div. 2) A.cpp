// Problem: A. Add or XOR
// Contest: Codeforces - Codeforces Round 1035 (Div. 2)
// URL: https://codeforces.com/contest/2119/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int a,b,x,y;
	cin>>a>>b>>x>>y;
	if (a-1 == b and a%2 == 1) cout<<y<<'\n'; 
	else if (a == b) cout<<"0\n";
	else if (a > b) cout<<"-1\n";
	else if (x <= y) cout<<(b-a)*x<<'\n';
	else {
		if (a%2 == b%2) cout<<(b-a)*(x+y)/2<<'\n';
		else if (a%2 == 0) cout<<(b-a)/2*x+(b-a)/2*y+y<<'\n';
		else cout<<(b-a)/2*x+(b-a)/2*y+x<<'\n';
	}
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









