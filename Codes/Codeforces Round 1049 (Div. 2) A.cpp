// Problem: A. Shift Sort
	// Contest: Codeforces - Codeforces Round 1049 (Div. 2)
// URL: https://codeforces.com/contest/2140/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int c1=ranges::count(s,'1');
	int ans=0;
	for(int i=n-1;c1!=0;i--) {
		if (s[i] == '0') ans++;
		c1--;
	}
	cout<<ans<<endl;
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









