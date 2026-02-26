// Problem: A. Dr. TC
// Contest: Codeforces - Codeforces Round 1020 (Div. 3)
// URL: https://codeforces.com/contest/2106/problem/A
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
	string s;
	cin>>n>>s;
	int cnt0=count(s.begin(),s.end(),'0');
	int cnt1=count(s.begin(),s.end(),'1');
	cout<<cnt1*(n-1)+cnt0<<endl;
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









