// Problem: C - Sugoroku Destination
// Contest: AtCoder - AtCoder Beginner Contest 445
// URL: https://atcoder.jp/contests/abc445/tasks/abc445_c
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> b(n);
	for(int i=0;i<n;i++) b[i]=i+1;
	for(int i=n-1;i>=0;i--) b[i]=b[a[i]-1];
	for(auto e1 : b) cout<<e1<<" ";
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







