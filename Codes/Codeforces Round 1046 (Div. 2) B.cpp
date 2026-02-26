// Problem: B. Like the Bitset
// Contest: Codeforces - Codeforces Round 1046 (Div. 2)
// URL: https://codeforces.com/contest/2136/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	for(int i=0;i<n;i++) {
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	
	int cnt=0,maxn=0;
	for(int i=0;i<n;i++) {
		if (a[i] == 1) cnt++;
		else maxn=max(maxn,cnt),cnt=0;
		if (i == n-1) maxn=max(maxn,cnt);
	}
	
	vector<int> ans(n);
	if (maxn >= k) cout<<"NO\n";
	else {
		int num=n;
		for(int i=0;i<n;i++) {
			if (a[i] == 0) ans[i]=num--;
		}
		for(int i=0;i<n;i++) {
			if (a[i] == 1) ans[i]=num--;
		}
		
		cout<<"YES\n";
		for(int i=0;i<n;i++) cout<<ans[i]<<' ';
		cout<<'\n';
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









