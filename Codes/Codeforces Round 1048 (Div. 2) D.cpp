// Problem: D. Antiamuny Wants to Learn Swap
// Contest: Codeforces - Codeforces Round 1048 (Div. 2)
// URL: https://codeforces.com/contest/2139/problem/D
// Memory Limit: 512 MB
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
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> sta;
	vector<int> l(n),r(n);
	for(int i=0;i<n;i++) {
		while (!sta.empty() and a[sta.back()] < a[i]) {
			sta.pop_back();
		}
		l[i]=sta.empty() ? -1 : sta.back();
		sta.push_back(i);
	}
	sta={};
	for(int i=n-1;i>=0;i--) {
		while (!sta.empty() and a[sta.back()] > a[i]) {
			sta.pop_back();
		}
		r[i]=sta.empty() ? n : sta.back();
		sta.push_back(i);
	}
	
	vector<int> f(n,n-1);
	for(int i=0;i<n;i++) {
		if (l[i] != -1 and r[i] != n) {
			f[l[i]]=min(f[l[i]],r[i]-1);
		}
	}
	for(int i=n-2;i>=0;i--) {
		f[i]=min(f[i+1],f[i]);
	}
	
	while (q--) {
		int L,R;
		cin>>L>>R;
		L--,R--;
		if (f[L] < R) cout<<"NO\n";
		else cout<<"YES\n";
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









