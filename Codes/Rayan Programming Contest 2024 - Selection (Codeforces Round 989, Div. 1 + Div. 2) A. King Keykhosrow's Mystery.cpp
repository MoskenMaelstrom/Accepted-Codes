// Problem: A. King Keykhosrow's Mystery
// Contest: Codeforces - Rayan Programming Contest 2024 - Selection (Codeforces Round 989, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2034/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int gcd(int a1,int a2)
{
	if (a1>a2) swap(a1,a2);
	return a1 ? gcd(a2%a1,a1) : a2;
}
int lcm(int a1,int a2)
{
	return a1*a2/gcd(a1,a2);
}
void solve()
{
	int a,b;
	cin>>a>>b;
	cout<<lcm(a,b)<<endl;
}
signed main()
{
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}