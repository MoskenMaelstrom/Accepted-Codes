// Problem: C. A Good Problem
// Contest: Codeforces - Codeforces Round 1035 (Div. 2)
// URL: https://codeforces.com/contest/2119/problem/C
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
	int n,l,r,k;
	cin>>n>>l>>r>>k;
	if (n%2 == 1) {
		cout<<l<<'\n';
	}
	else if (n == 2) cout<<"-1\n";
	else {
		int num=1;
		while (num < r) {
			num<<=1;
			if (num <= l or num > r) continue;
			else {
				if (k == n or k == n-1) cout<<num<<'\n';
				else cout<<l<<'\n';
				return;
			}
		}
		cout<<"-1\n";
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









