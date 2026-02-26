// Problem: A. Common Multiple
// Contest: Codeforces - Codeforces Round 1019 (Div. 2)
// URL: https://codeforces.com/contest/2103/problem/0
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
	set<int> st;
	int cnt=0;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		if (st.find(x) == st.end()) st.insert(x);
		else cnt++;
	}
	cout<<n-cnt<<endl;
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









