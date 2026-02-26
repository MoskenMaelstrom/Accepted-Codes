// Problem: C. Cool Partition
// Contest: Codeforces - Codeforces Round 1029 (Div. 3)
// URL: https://codeforces.com/contest/2117/problem/C
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
	set<int> st,st1;
	st.insert(a[0]);
	
	auto ok=[&]() {
		for(auto e1 : st) {
			if (st1.contains(e1)) continue;
			else return 0;
		}
		return 1;
	};
	
	int cnt=1;
	for(int i=1;i<n;i++) {
		st1.insert(a[i]);
		if (ok()) {cnt++;st=st1;st1.clear();}
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









