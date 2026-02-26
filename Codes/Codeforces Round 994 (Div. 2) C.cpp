// Problem: C. MEX Cycle
// Contest: Codeforces - Codeforces Round 994 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2049/C
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
	int n,x,y;
	cin>>n>>x>>y;
	x--,y--;
	vector<int> a(n,0);
	for(int i=0;i<n;i++) {
		if (i&1) a[i]=1;
	}
	if (n&1) a[n-1]=2;
	
	if (a[x] == a[y]) {
		if (x == 0 and (n&1)) {
			swap(a[x],a[n-1]);
		}
		else a[x]=2;
	}
	
	for(auto e1 : a) cout<<e1<<" ";
	cout<<"\n";
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









