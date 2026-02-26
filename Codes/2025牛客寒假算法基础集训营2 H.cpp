// Problem: 一起画很大的圆！
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95334/H
// Memory Limit: 2048 MB
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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int w=b-a,h=d-c;
	if (w > h) {
		cout<<b<<" "<<d<<"\n";
		cout<<b-1<<" "<<d<<"\n";
		cout<<a<<" "<<d-1<<"\n";
	}
	else {
		cout<<b<<" "<<d<<"\n";
		cout<<b<<" "<<d-1<<"\n";
		cout<<b-1<<" "<<c<<"\n";
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









