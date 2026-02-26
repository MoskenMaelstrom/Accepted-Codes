// Problem: A. Olympiad Date
// Contest: Codeforces - Codeforces Round 1013 (Div. 3)
// URL: https://codeforces.com/contest/2091/problem/0
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;


void solve()
{
	int n;
	cin>>n;
	vector<int> b(10,0);
	bool flag=0;
	for(int i=0;i<n;i++) {
		int a;
		cin>>a;
		b[a]++;
		if (!flag and b[0] >= 3 and b[1] >= 1 and b[2] >= 2 and b[3] >= 1 and b[5] >= 1) {cout<<i+1<<endl;flag=1;}
	}
	// for (auto e1 : b) cout<<e1<<" ";
	// cout<<endl;
	if (!flag) cout<<0<<endl;
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









