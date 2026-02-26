// Problem: D. Creating a Schedule
// Contest: Codeforces - Educational Codeforces Round 179 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2111/problem/D
// Memory Limit: 512 MB
// Time Limit: 2500 ms
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
	int n,m;
	cin>>n>>m;
	vector<int> a(m);
	for(int i=0;i<m;i++) cin>>a[i];
	ranges::sort(a);
	
	for(int i=0;i<n;i++) {
		int c=i/2;
		if (i%2 == 0) {
			cout<<a[c]<<" "<<a[m-1-c]<<" ";
			cout<<a[c]<<" "<<a[m-1-c]<<" ";
			cout<<a[c]<<" "<<a[m-1-c]<<"\n";
		}
		else {
			cout<<a[m-1-c]<<" "<<a[c]<<" ";
			cout<<a[m-1-c]<<" "<<a[c]<<" ";
			cout<<a[m-1-c]<<" "<<a[c]<<"\n";
		}
	}
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









