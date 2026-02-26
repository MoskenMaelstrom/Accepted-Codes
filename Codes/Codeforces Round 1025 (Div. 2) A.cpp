// Problem: A. It's Time To Duel
// Contest: Codeforces - Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/contest/2109/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	bool ok=0;
	if (count(a.begin(),a.end(),1) == 0) ok=1;
	if (count(a.begin(),a.end(),0) == 0) ok=1;
	for(int i=0;i<n-1;i++) {
		// if (a[i] == 1 and a[i+1] == 1) ok=1;
		if (a[i] == 0 and a[i+1] == 0) ok=1;
	}
	
	if (ok) cout<<"Yes\n";
	else cout<<"No\n";
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









