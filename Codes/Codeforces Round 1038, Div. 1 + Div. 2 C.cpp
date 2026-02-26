// Problem: C. Manhattan Pairs
// Contest: Codeforces - Order Capital Round 1 (Codeforces Round 1038, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2122/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	int n;
	cin>>n;
	vector<array<int,3>> a(n);
	for(int i=0;i<n;i++) {cin>>a[i][0]>>a[i][1];a[i][2]=i+1;}
	
	vector<array<int,3>> a1,a2;
	ranges::sort(a);
	for(int i=0;i<n/2;i++) a1.push_back({a[i][1],a[i][0],a[i][2]});
	for(int i=n/2;i<n;i++) a2.push_back({a[i][1],a[i][0],a[i][2]});
	
	ranges::sort(a1);
	ranges::sort(a2,greater<array<int,3>>());
	
	for(int i=0;i<n/2;i++) {
		cout<<a1[i][2]<<" "<<a2[i][2]<<"\n";
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









