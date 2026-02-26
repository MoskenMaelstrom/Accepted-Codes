// Problem: B. Floor or Ceil
// Contest: Codeforces - Codeforces Round 1010 (Div. 2, Unrated)
// URL: https://codeforces.com/problemset/problem/2082/B
// Memory Limit: 512 MB
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
	int x,n,m;
	cin>>x>>n>>m;
	n=min(n,32ll);
	m=min(m,32ll);
	int x1=x;
	int n1=n;
	int m1=m;
	while (n != 0 or m != 0) {
		while (m != 0) {x=x+1>>1;m--;}
		while (n != 0) {x>>=1;n--;}
	}
	cout<<x<<" ";
	x=x1;
	n=n1;
	m=m1;
	while (n != 0 or m != 0) {
		while (n != 0) {x>>=1;n--;}
		while (m != 0) {x=x+1>>1;m--;}
	}
	cout<<x<<endl;
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









