// Problem: E. Changing the String
// Contest: Codeforces - Educational Codeforces Round 179 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2111/problem/E
// Memory Limit: 512 MB
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
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	
	set<int> st[6];
	for(int i=0;i<q;i++) {
		char e1,e2;
		cin>>e1>>e2;
		if (e1 == 'a' and e2 == 'b') st[0].insert(i);
		if (e1 == 'b' and e2 == 'a') st[1].insert(i);
		if (e1 == 'c' and e2 == 'b') st[2].insert(i);
		if (e1 == 'b' and e2 == 'c') st[3].insert(i);
		if (e1 == 'a' and e2 == 'c') st[4].insert(i);
		if (e1 == 'c' and e2 == 'a') st[5].insert(i);
	}
	
	for(int i=0;i<n;i++) {
		if (s[i] == 'a') continue;
		if (s[i] == 'b') {
			if (!st[1].empty()) {s[i]='a';st[1].erase(st[1].begin());}
			else if (!st[3].empty() and !st[5].empty()) {
				auto it=st[5].upper_bound(*st[3].begin());
				if (it != st[5].end()) {s[i]='a';st[3].erase(st[3].begin());st[5].erase(it);}
			}
		}
		if (s[i] == 'c') {
			if (!st[5].empty()) {s[i]='a';st[5].erase(st[5].begin());}
			else if (!st[2].empty() and !st[1].empty()) {
				auto it=st[1].upper_bound(*st[2].begin());
				if (it != st[1].end()) {s[i]='a';st[2].erase(st[2].begin());st[1].erase(it);}
			}
			
			if (s[i] == 'c' and !st[2].empty()) {s[i]='b';st[2].erase(--st[2].end());}
		}
	}
	cout<<s<<endl;
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









