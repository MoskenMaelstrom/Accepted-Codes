// Problem: P1063 [NOIP 2006 提高组] 能量项链
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1063
// Memory Limit: 128 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<=n;i++) a.push_back(a[i]);
	
	map<array<int,2>,int> mp;
	auto dfs=[&](this auto&& self,int l,int r) -> int {
		if (l == r) return 0;
		if (l == r-1) return a[l]*a[l+1]*a[l+2];
		if (mp.count({l,r})) return mp[{l,r}];
		
		int res=0;
		for(int k=l;k<r;k++) {
			res=max(res,self(l,k)+self(k+1,r)+a[l]*a[k+1]*a[r+1]);
		}
		mp[{l,r}]=res;
		return res;
	};
	
	int ans=0;
	for(int i=0;i<2*n-1;i++) {
		ans=max(ans,dfs(i,i+n-1));
	}
	cout<<ans;
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









