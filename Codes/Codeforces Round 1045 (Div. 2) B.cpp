// Problem: B. Add 0 or K
// Contest: Codeforces - Codeforces Round 1045 (Div. 2)
// URL: https://codeforces.com/contest/2134/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<n;i++) {
		a[i]+=a[i]%(k+1)*k;
	}
	for(auto e1 : a) cout<<e1<<' ';
	cout<<'\n';
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









