// Problem: F. Counting Necessary Nodes
// Contest: Codeforces - Codeforces Round 1009 (Div. 3)
// URL: https://codeforces.com/contest/2074/problem/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int x0,x1,y0,y1;
	cin>>x0>>x1>>y0>>y1;
	int n=22;
	auto work=[&](this auto &&self,int x0,int x1,int y0,int y1) -> int {
		if (x0 == x1 or y0 == y1) return 0;
		if (x1-x0 > y1-y0) return self(y0,y1,x0,x1);
		int res=0;
		for(int x=x0;x<x1;) {
			int r0=min(n,(i64)countr_zero(u64(x)));
			while (x+(1<<r0) > x1) r0--;
			int wid=1<<r0;
			int t0=y0>>r0<<r0,t1=y1>>r0<<r0;
			while (t0 < y0) t0+=wid;
			if (t1 > t0) res+=(t1-t0)/wid;
			res+=self(x,x+wid,y0,t0)+self(x,x+wid,t1,y1);
			x+=wid;
		}
		return res;
	};
	cout<<work(x0,x1,y0,y1)<<endl;
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









