// Problem: C - Buy Balls
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_c
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
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	for(auto &e1 : a) cin>>e1;
	for(auto &e1 : b) cin>>e1;
	ranges::sort(a);
	ranges::reverse(a);
	ranges::sort(b);
	ranges::reverse(b);
	int ans=0;
	for(int i=0;i<n;i++) {
		if (n >= m and i >= m and a[i] > 0) ans+=a[i];
		else if (i < m) {
			if (a[i] >= 0 and b[i] >= 0) ans+=a[i]+b[i];
			else if (a[i] >= 0 and b[i] < 0) ans+=a[i];
			else if (a[i] < 0 and a[i]+b[i] >= 0) ans+=a[i]+b[i];
		}
	}
	
	cout<<ans<<endl;
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









