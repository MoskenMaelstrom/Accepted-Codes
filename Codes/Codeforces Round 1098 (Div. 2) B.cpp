// Problem: B. Remilia Plays Soku
// Contest: Codeforces - Codeforces Round 1098 (Div. 2)
// URL: https://codeforces.com/contest/2228/problem/B
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
	int n,x1,x2,k;
	cin>>n>>x1>>x2>>k;
	if (n <= 3) cout<<min(abs(x1-x2),n-abs(x1-x2))<<"\n";
	else cout<<k+min(abs(x1-x2),n-abs(x1-x2))<<"\n";
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







