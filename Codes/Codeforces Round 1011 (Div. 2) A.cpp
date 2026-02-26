// Problem: A. Serval and String Theory
// Contest: Codeforces - Codeforces Round 1011 (Div. 2)
// URL: https://codeforces.com/contest/2085/problem/0
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
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	if (n == 1) cout<<"NO\n";
	else if (k == 0) {
		string s1=s;
		ranges::reverse(s);
		if (s1 < s) cout<<"YES\n";
		else cout<<"NO\n";
	}
	else {
		set<char> st;
		for(int i=0;i<n;i++) {
			st.insert(s[i]);
		}
		if (st.size() == 1) cout<<"NO\n";
		else cout<<"YES\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









