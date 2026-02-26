// Problem: E. Arithmetics Competition
// Contest: Codeforces - Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2132/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	vector<int> a(n),b(m);
	vector<array<int,2>> c;
	for(int i=0;i<n;i++) {cin>>a[i];c.push_back({a[i],0});}
	for(int i=0;i<m;i++) {cin>>b[i];c.push_back({b[i],1});}
	ranges::sort(a,greater<int>());
	ranges::sort(b,greater<int>());
	ranges::sort(c,greater<array<int,2>>());

	vector<array<int,2>> cnt(n+m);
	if (c[0][1] == 0) cnt[0][0]++;
	else cnt[0][1]++;
	for(int i=1;i<n+m;i++) {
		cnt[i][0]=cnt[i-1][0];
		cnt[i][1]=cnt[i-1][1];
		if (c[i][1] == 0) cnt[i][0]++;
		else cnt[i][1]++;
	}
	
	vector<int> a1(n),b1(m),c1(n+m);
	a1[0]=a[0];
	b1[0]=b[0];
	c1[0]=c[0][0];
	for(int i=1;i<n;i++) a1[i]=a1[i-1]+a[i];
	for(int i=1;i<m;i++) b1[i]=b1[i-1]+b[i];
	for(int i=1;i<n+m;i++) c1[i]=c1[i-1]+c[i][0];
	
	while (q--) {
		int x,y,z;
		cin>>x>>y>>z;
		if (z == 0) {cout<<"0\n";continue;}
		if (x == 0) {cout<<b1[z-1]<<"\n";continue;}
		if (y == 0) {cout<<a1[z-1]<<"\n";continue;}
		int x1,y1;
		x1=cnt[z-1][0];
		y1=cnt[z-1][1];
		if (x1 <= x and y1 <= y) cout<<c1[z-1]<<"\n";
		else if (x1 > x) cout<<a1[x-1]+b1[z-x-1]<<"\n";
		else cout<<a1[z-y-1]+b1[y-1]<<"\n";
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









