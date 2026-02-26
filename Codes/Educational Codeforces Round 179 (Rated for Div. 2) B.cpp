// Problem: B. Fibonacci Cubes
// Contest: Codeforces - Educational Codeforces Round 179 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2111/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
// #define int long long
using namespace std;

int b[11]={0,1,2,3,5,8,13,21,34,55,89};
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		vector<int> a(3);
		cin>>a[0]>>a[1]>>a[2];
		ranges::sort(a);
		int b1=b[n]+b[n-1];
		int b2=b[n];
		if (b1 <= a[2] and b2 <= a[1] and b2 <= a[0]) cout<<1;
		else cout<<0;
	}
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









