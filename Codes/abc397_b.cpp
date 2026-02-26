// Problem: B - Ticket Gate Log
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_b
// Memory Limit: 1024 MB
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
	string s;
	cin>>s;
	int pos=0;
	int cnt=0;
	while (1) {
		if (pos == s.length()) break;
		if (pos%2 == 0) {
			if (s[pos] == 'i') pos++;
			else {
				s.insert(pos,1,'i');
				pos++;
				cnt++;
			}
		}
		else {
			if (s[pos] == 'o') pos++;
			else {
				s.insert(pos,1,'o');
				pos++;
				cnt++;
			}
		}
	}
	if (s[s.length()-1] == 'i') cnt++;
	cout<<cnt;
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









