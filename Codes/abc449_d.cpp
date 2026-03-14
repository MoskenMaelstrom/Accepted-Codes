// Problem: D - Make Target 2
// Contest: AtCoder - AtCoder Beginner Contest 449
// URL: https://atcoder.jp/contests/abc449/tasks/abc449_d
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
	int l,r,d,u;
	cin>>l>>r>>d>>u;
	int ans=0;
	for(int i=l;i<=r;i++) {
		int x=abs(i);
		int y1=max(d,-x);
		int y2=min(u,x);
		if (y1 <= y2 and x%2 == 0) ans+=y2-y1+1;
		
		y1=max(d,x+1);
		y2=u;
		if (y1&1) y1++;
		if (y2&1) y2--;
		if (y2-y1 >= 0) ans+=(y2-y1)/2+1;
		
		y1=d;
		y2=min(u,-x-1);
		if (y1&1) y1++;
		if (y2&1) y2--;
		if (y2-y1 >= 0) ans+=(y2-y1)/2+1;
	}
	cout<<ans;
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







