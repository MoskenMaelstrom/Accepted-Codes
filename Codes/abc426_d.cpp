// Problem: D - Pop and Insert
// Contest: AtCoder - AtCoder Beginner Contest 426
// URL: https://atcoder.jp/contests/abc426/tasks/abc426_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	int len0=0,cnt0=0;
	for(int i=0;i<n;i++) {
		if (s[i] == '0') cnt0++;
		else cnt0=0;
		len0=max(len0,cnt0);
	}
	int len1=0,cnt1=0;
	for(int i=0;i<n;i++) {
		if (s[i] == '1') cnt1++;
		else cnt1=0;
		len1=max(len1,cnt1);
	}
	
	int c0=ranges::count(s,'0');
	int c1=ranges::count(s,'1');
	
	cout<<min(n-len1+(c1-len1), n-len0+(c0-len0))<<'\n';
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









