// Problem: D1. Removal of a Sequence (Easy Version)
// Contest: Codeforces - Educational Codeforces Round 184 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2169/problem/D1
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e12;
void solve()
{
	int x,y,k;
	cin>>x>>y>>k;
	if (y == 1) {
		cout<<"-1\n";
	}
	else {
		int ans=k;
		for(int i=0;i<x;i++) {
			ans=ans+(ans-1)/(y-1);
			if (ans > inf) {cout<<"-1\n";return;}
		}
		cout<<ans<<"\n";
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







