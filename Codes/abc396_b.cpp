// Problem: B - Card Pile
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

void solve()
{
	stack<int> a;
	int t;
	cin>>t;
	while (t--) 
	{
		int opt;
		cin>>opt;
		if (opt == 1) {
			int n;
			cin>>n;
			a.push(n);
		}
		else {
			if (a.empty()) cout<<0<<endl;
			else {cout<<a.top()<<endl;a.pop();}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









