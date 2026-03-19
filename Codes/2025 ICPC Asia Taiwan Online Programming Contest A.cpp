// Problem: A. Take It or Double It
// Contest: Codeforces - 2025 ICPC Asia Taiwan Online Programming Contest
// URL: https://codeforces.com/gym/106084/problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int a,b;
	cin>>a>>b;
	if (a*2 > b) cout<<"take it";
	else cout<<"double it";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







