// Problem: B. St. Chroma
// Contest: Codeforces - Codeforces Round 1020 (Div. 3)
// URL: https://codeforces.com/contest/2106/problem/B
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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	int cnt=0;
	for(int i=0;i<k;i++) a[i]=cnt++;
	for(int i=n-1;i>=k;i--) a[i]=cnt++;
	for(int i=0;i<n;i++) cout<<a[i]<<" \n"[i == n-1];
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









