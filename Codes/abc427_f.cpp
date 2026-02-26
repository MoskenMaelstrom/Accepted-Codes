// Problem: F - Not Adjacent
// Contest: AtCoder - Panasonic Programming Contest 2025（AtCoder Beginner Contest 427）
// URL: https://atcoder.jp/contests/abc427/tasks/abc427_f
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	int cnt=0;
	unordered_map<int,int> mp0,mp1;
	auto dfs1=[&](auto self,int p,int sum,bool mask) -> void {
		if (p == n/2-1 and mask or p == n/2 and !mask) {
			mp0[sum%m]++;
			return;
		}
		else if (p == n/2 and mask) {
			mp1[sum%m]++;
			return;
		}
		
		if (mask) {
			if (p+2 <= n/2) self(self,p+2,sum,0);
			if (p+2 <= n/2) self(self,p+2,sum+a[p+2],1);
		}
		else {
			if (p+1 <= n/2) self(self,p+1,sum,0);
			if (p+1 <= n/2) self(self,p+1,sum+a[p+1],1);
		}
	};
	
	auto dfs2=[&](auto self,int p,int sum,bool mask) -> void {
		if (p == n or p == n-1 and mask) {
			cnt+=mp0[(m-sum%m)%m]+mp1[(m-sum%m)%m];
			return;
		}
		
		if (mask) {
			if (p+2 <= n) self(self,p+2,sum,0);
			if (p+2 <= n) self(self,p+2,sum+a[p+2],1);
		}
		else {
			if (p+1 <= n) self(self,p+1,sum,0);
			if (p+1 <= n) self(self,p+1,sum+a[p+1],1);
		}
	};
	
	auto dfs3=[&](auto self,int p,int sum,bool mask) -> void {
		if (p == n or p == n-1 and mask) {
			cnt+=mp0[(m-sum%m)%m];
			return;
		}
		
		if (mask) {
			if (p+2 <= n) self(self,p+2,sum,0);
			if (p+2 <= n) self(self,p+2,sum+a[p+2],1);
		}
		else {
			if (p+1 <= n) self(self,p+1,sum,0);
			if (p+1 <= n) self(self,p+1,sum+a[p+1],1);
		}
	};
	
	dfs1(dfs1,0,0,0);
	dfs2(dfs2,n/2+1,0,0);
	dfs3(dfs3,n/2+1,a[n/2+1],1);
	
	cout<<cnt;
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