// Problem: A. Carnival Wheel
// Contest: Codeforces - Codeforces Global Round 31 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2180/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,a,b;
	cin>>n>>a>>b;
	cout<<a%gcd(n,b)+n-gcd(n,b)<<"\n";
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







