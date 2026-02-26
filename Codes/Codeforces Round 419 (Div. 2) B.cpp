// Problem: B. Karen and Coffee
// Contest: Codeforces - Codeforces Round 419 (Div. 2)
// URL: https://codeforces.com/problemset/problem/816/B
// Memory Limit: 512 MB
// Time Limit: 2500 ms
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

const int N=2e5+10;
void solve()
{
	int n,k,q;
	cin>>n>>k>>q;
	vector<array<int,2>> a(n);
	vector<int> c(N);
	for(int i=0;i<n;i++) {
		cin>>a[i][0]>>a[i][1];
		c[a[i][0]]++;
		c[a[i][1]+1]--;
	}
	for(int i=1;i<N;i++) {
		c[i]+=c[i-1];
	}	
	
	vector<int> pre(N);
	for(int i=0;i<N;i++) {
		if (c[i] >= k) pre[i]=1;
	}
	for(int i=1;i<N;i++) {
		pre[i]+=pre[i-1];
	}
	
	while (q--) {
		int l,r;
		cin>>l>>r;
		cout<<pre[r]-pre[l-1]<<'\n';
	}
	
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









