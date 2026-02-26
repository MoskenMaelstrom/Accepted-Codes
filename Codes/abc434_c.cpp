// Problem: C - Flapping Takahashi
// Contest: AtCoder - Ｓｋｙ Inc, Programming Contest 2025 (AtCoder Beginner Contest 434)
// URL: https://atcoder.jp/contests/abc434/tasks/abc434_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,h;
	cin>>n>>h;
	int ok=1;
	int lo=h,hi=h;
	int T=0;
	for(int i=0;i<n;i++) {
		int t,l,r;
		cin>>t>>l>>r;
		int cha=t-T;
		T=t;
		hi+=cha,lo-=cha;
		lo=max(0ll,lo);
		if (hi < l or lo > r) ok=0;
		hi=min(hi,r);
		lo=max(lo,l);
	}
	if (ok) cout<<"Yes\n";
	else cout<<"No\n";
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







