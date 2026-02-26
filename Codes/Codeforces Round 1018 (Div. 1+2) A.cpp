// Problem: A. Wonderful Sticks
// Contest: Codeforces - Neowise Labs Contest 1 (Codeforces Round 1018, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2096/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int n;
	cin>>n;
	vector<int> a(n);
	string s;
	cin>>s;
	
	int c=0;
	for(int i=n-2;i>=0;i--) {
		if (s[i] == '<') a[i+1]=++c;
		if (i == 0) a[i]=++c;
	}
	c=n+1;
	for(int i=n-2;i>=0;i--) {
		if (s[i] == '>') a[i+1]=--c;
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" \n"[i == n-1];
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









