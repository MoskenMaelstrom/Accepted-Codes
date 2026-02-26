// Problem: D. Skibidi Table
// Contest: Codeforces - Codeforces Round 1016 (Div. 3)
// URL: https://codeforces.com/contest/2093/problem/D
// Memory Limit: 256 MB
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	while (q--) {
		string opt;
		cin>>opt;
		if (opt == "->") {
			int x,y;
			cin>>x>>y;
			x--;
			y--;
			int ans=1;
			for(int i=0;i<n;i++) {
				int xi=x>>i&1;
				int yi=y>>i&1;
				if (xi == 1 and yi == 1) ans+=(1ll<<(i*2));
				if (xi == 1 and yi == 0) ans+=(1ll<<(i*2))*2;
				if (xi == 0 and yi == 1) ans+=(1ll<<(i*2))*3;
			}
			cout<<ans<<endl;
		}
		else {
			int d;
			cin>>d;
			d--;
			int x=1,y=1;
			for(int i=0;i<n;i++) {
				int p=(d>>(2*i))&1;
				int q=(d>>(2*i+1))&1;
				if (q == 0 and p == 1) {x+=1ll<<i;y+=1ll<<i;}
				if (q == 1 and p == 1) y+=1ll<<i;
				if (q == 1 and p == 0) x+=1ll<<i;
			}
			cout<<x<<" "<<y<<endl;
		}
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









