// Problem: A - Happy Birthday! 4
// Contest: AtCoder - AtCoder Beginner Contest 433
// URL: https://atcoder.jp/contests/abc433/tasks/abc433_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int x,y,z;
	cin>>x>>y>>z;
	for(int i=0;i<10000;i++) {
		if (y*z == x) {cout<<"Yes";return;}
		x++,y++;
	}
	cout<<"No";
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







