// Problem: C. Maximum GCD on Whiteboard
// Contest: Codeforces - Codeforces Round 1061 (Div. 2)
// URL: https://codeforces.com/contest/2156/problem/C
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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> cnt(n+1);
	for(int i=0;i<n;i++) cnt[a[i]]++;
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+cnt[i];
	for(int i=n;i>=1;i--) {
		int sum=pre[min(4*i-1,n)];
		int cnt1=0;
		if (i <= n) cnt1+=cnt[i];
		if (2*i <= n) cnt1+=cnt[2*i];
		if (3*i <= n) cnt1+=cnt[3*i];
		if (sum-cnt1 <= k) {cout<<i<<"\n";return;}
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









