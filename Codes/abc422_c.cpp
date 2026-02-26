// Problem: C - AtCoder AAC Contest
// Contest: AtCoder - AtCoder Beginner Contest 422
// URL: https://atcoder.jp/contests/abc422/tasks/abc422_c
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
	int a,b,c;
	cin>>a>>b>>c;
	b+=abs(a-c);
	a=c=min(a,c);
	int ans;
	if (b >= a) {
		ans=a;
	}
	else {
		a-=b,c-=b;
		ans=a*2/3+b;
	}
	cout<<ans<<"\n";
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









