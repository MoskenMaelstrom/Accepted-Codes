// Problem: C. Neo's Escape
// Contest: Codeforces - Codeforces Round 1022 (Div. 2)
// URL: https://codeforces.com/contest/2108/problem/C
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	a.erase(unique(a.begin(),a.end()),a.end());
	
	n=a.size();
	int cnt=0;
	if (n != 1) {
		if (a[0] > a[1]) cnt++;
		if (a[n-1] > a[n-2]) cnt++;
	}
	else cnt++;
	for(int i=1;i<n-1;i++) {
		if (a[i-1] < a[i] and a[i] > a[i+1]) cnt++;
	}
	cout<<cnt<<endl;
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









