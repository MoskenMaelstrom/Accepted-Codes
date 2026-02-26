// Problem: A - Twice Subsequence
// Contest: AtCoder - AtCoder Regular Contest 195 (Div. 2)
// URL: https://atcoder.jp/contests/arc195/tasks/arc195_a
// Memory Limit: 1024 MB
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	for(auto &e1 : a) cin>>e1;
	for(auto &e1 : b) cin>>e1;
	
	int p=0;
	int flag=0;
	for(int i=0;i<n;i++) {
		if (p < m and a[i] == b[p]) {
			p++;
		}
		else if (p != 0 and a[i] == b[p-1]) {
			flag=1;
		}
	}
	
	if (p == m and flag) cout<<"Yes";
	else cout<<"No";
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









