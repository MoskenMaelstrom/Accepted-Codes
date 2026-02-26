// Problem: P3146 [USACO16OPEN] 248 G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3146
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	map<array<int,2>,int> mp;
	int ans=*ranges::max_element(a);
	auto dfs=[&](this auto&& self,int l,int r) -> int {
		if (l == r) return a[l];
		if (mp.count({l,r})) return mp[{l,r}];
		
		int res=0;
		for(int k=l;k<r;k++) {
			if (self(l,k) != 0 and self(l,k) == self(k+1,r)) {
				res=max(res,self(l,k)+1);
			}
		}
		ans=max(ans,res);
		mp[{l,r}]=res;
		return res;
	};
	
	dfs(0,n-1);
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









