// Problem: A. Slimes on a Line
// Contest: Codeforces - Spectral::Cup 2026 Round 2 (Codeforces Round 1100, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2229/problem/A
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int a1=*ranges::max_element(a);
	int a2=*ranges::min_element(a);
	cout<<(a1-a2+1)/2<<"\n";
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







