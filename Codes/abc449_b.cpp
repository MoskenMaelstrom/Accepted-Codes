// Problem: B - Deconstruct Chocolate
// Contest: AtCoder - AtCoder Beginner Contest 449
// URL: https://atcoder.jp/contests/abc449/tasks/abc449_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	while (q--) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int R;
			cin>>R;
			cout<<R*m<<"\n";
			n-=R;
		}
		else {
			int R;
			cin>>R;
			cout<<R*n<<"\n";
			m-=R;
		}
	}
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







