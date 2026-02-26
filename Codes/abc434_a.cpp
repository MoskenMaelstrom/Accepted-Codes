// Problem: A - Balloon Trip
// Contest: AtCoder - Ｓｋｙ Inc, Programming Contest 2025 (AtCoder Beginner Contest 434)
// URL: https://atcoder.jp/contests/abc434/tasks/abc434_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int w,b;
	cin>>w>>b;
	w*=1000;
	int n=w/b;
	if (w>=n*b) n++;
	cout<<n;
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







