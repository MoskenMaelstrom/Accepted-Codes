// Problem: A - π
// Contest: AtCoder - AtCoder Beginner Contest 449
// URL: https://atcoder.jp/contests/abc449/tasks/abc449_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const double pi=acos(-1);
void solve()
{
	int d;
	cin>>d;
	double r=(double)d/2;
	cout<<fixed<<setprecision(10)<<r*r*pi;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







