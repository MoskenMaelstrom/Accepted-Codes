// Problem: B. Above the Clouds
// Contest: Codeforces - Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/contest/2121/problem/B
// Memory Limit: 256 MB
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
	int n;
	string s;
	cin>>n>>s;
	map<char,int> mp1;
	map<char,int> mp2;
	for(int i=0;i<n-1;i++) {
		mp1[s[i]]++;
	}
	for(int i=1;i<n;i++) {
		mp2[s[i]]++;
	}
	
	bool ok=0;
	for(auto [e1,e2] : mp1) {
		if (e2 >= 2) ok=1;
	}
	for(auto [e1,e2] : mp2) {
		if (e2 >= 2) ok=1;
	}
	
	if (ok) cout<<"Yes\n";
	else cout<<"No\n";
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









