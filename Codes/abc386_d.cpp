// Problem: D - Diagonal Separation
// Contest: AtCoder - AtCoder Beginner Contest 386
// URL: https://atcoder.jp/contests/abc386/tasks/abc386_d
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
	int n,m;
	cin>>n>>m;
	map<int,vector<array<int,2>>> mp;
	for(int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		char c;
		cin>>c;
		if (c == 'B') mp[x].push_back({y,1});
		else mp[x].push_back({y,0});
	}
	
	int r=n;
	bool ok=1;
	for(auto [x,vec] : mp) {
		int L=0,R=n+1;
		for(auto [y,c] : vec) {
			if (c == 1) L=max(L,y);
			else R=min(R,y);
		}
		if (L >= R or L > r) ok=0;
		r=min(r,R-1);
	}
	
	if (ok) cout<<"Yes";
	else cout<<"No";
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







