// Problem: A. Zhily and Array Operating
// Contest: Codeforces - Codeforces Round 1097 (Div. 2,  Based on Zhili Cup 2026)
// URL: https://codeforces.com/contest/2224/problem/A
// Memory Limit: 512 MB
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
	for(int i=n-2;i>=0;i--) {
		if (a[i+1] >= 0) a[i]+=a[i+1];
	}
	int cnt=0;
	for(int i=0;i<n;i++) {
		if (a[i] > 0) cnt++;
	}
	cout<<cnt<<"\n";
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







