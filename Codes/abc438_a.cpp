// Problem: A - First Contest of the Year
// Contest: AtCoder - AtCoder Beginner Contest 438
// URL: https://atcoder.jp/contests/abc438/tasks/abc438_a
// Memory Limit: 1024 MB
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
	int d,f;
	cin>>d>>f;
	int m=(d-f)/7;
	cout<<f+7*(m+1)-d;
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







