// Problem: F. Trulimero Trulicina
// Contest: Codeforces - Codeforces Round 1017 (Div. 4)
// URL: https://codeforces.com/contest/2094/problem/F
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
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	if (m%k != 0) {
		for(int i=0;i<n*m;i++) {
			if (i%m == m-1) cout<<i%k+1<<endl;
			else cout<<i%k+1<<" ";
		}
	}
	else {
		bool f=0;
		for(int i=0;i<n*m;i++) {
			if (f) {
				if (i%k+2 == k+1) cout<<1;
				else cout<<i%k+2;
				
				if (i%m == m-1) {f=!f;cout<<endl;}
				else cout<<" ";
			}
			else {
				if (i%m == m-1) {cout<<i%k+1<<endl;f=!f;}
				else cout<<i%k+1<<" ";
			}
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









