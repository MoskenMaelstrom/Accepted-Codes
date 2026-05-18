// Problem: A. Marisa Steals Reimu's Takeout
// Contest: Codeforces - Codeforces Round 1098 (Div. 2)
// URL: https://codeforces.com/contest/2228/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> c(3);
	for(int i=0;i<n;i++) {
		c[a[i]%3]++;
	}
	int cnt=c[0];
	int minx=min(c[1],c[2]);
	cnt+=minx;
	c[1]-=minx;
	c[2]-=minx;
	cout<<cnt+c[1]/3+c[2]/3<<"\n";
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







