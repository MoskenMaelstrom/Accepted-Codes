// Problem: J. Odd-Even Game
// Contest: Codeforces - The 18th Jilin Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105922/problem/J
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
	int n0,n1;
	cin>>n0>>n1;
	if (n0&1) swap(n0,n1);
	if (n1 > n0) cout<<1;
	else cout<<2;
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







