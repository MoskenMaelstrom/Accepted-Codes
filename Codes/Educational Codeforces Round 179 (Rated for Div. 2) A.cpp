// Problem: A. Energy Crystals
// Contest: Codeforces - Educational Codeforces Round 179 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2111/problem/0
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
	int n;
	cin>>n;
	int cnt=0;
	while (n) {
		cnt++;
		n/=2;
	}
	cout<<2*cnt+1<<endl;
	
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









