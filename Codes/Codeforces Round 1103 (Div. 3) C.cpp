// Problem: C. Omsk Programmers
// Contest: Codeforces - Codeforces Round 1103 (Div. 3)
// URL: https://codeforces.com/contest/2236/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int a,b,x;
	cin>>a>>b>>x;
	int ans=1e18;
	int cur=0;
	while (1) {
		if (a < b) swap(a,b);
		ans=min(ans,cur+a-b);
		if (a == b) break;
		a/=x;
		cur++;
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







