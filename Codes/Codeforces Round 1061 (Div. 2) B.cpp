// Problem: B. Strange Machine
// Contest: Codeforces - Codeforces Round 1061 (Div. 2)
// URL: https://codeforces.com/contest/2156/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	while (q--) {
		int m;
		cin>>m;
		if (ranges::count(s,'B') == 0) {
			cout<<m<<"\n";
		}
		else {
			int p=0,cnt=0;
			while (m != 0) {
				if (s[p] == 'A') m--;
				else m>>=1;
				p++;
				p%=n;
				cnt++;
			}
			cout<<cnt<<"\n";
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









