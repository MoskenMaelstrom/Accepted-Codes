// Problem: C - Alternated
// Contest: AtCoder - AtCoder Beginner Contest 421
// URL: https://atcoder.jp/contests/abc421/tasks/abc421_c
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
	int ans1=0,ans2=0;
	int cur=0;
	for(int i=0;i<2*n;i++) {
		if (s[i] == 'A') ans1+=abs(i-cur),cur+=2;
	}
	cur=1;
	for(int i=0;i<2*n;i++) {
		if (s[i] == 'A') ans2+=abs(i-cur),cur+=2;
	}
	
	cout<<min(ans1,ans2);
}

signed main()
{]
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









