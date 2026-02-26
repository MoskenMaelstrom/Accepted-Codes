// Problem: P1880 [NOI1995] 石子合并
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1880
// Memory Limit: 125 MB
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

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++) a.push_back(a[i]);
	vector<int> pre(2*n);
	for(int i=1;i<=2*n;i++) pre[i]+=pre[i-1]+a[i];
	
	map<array<int,2>,int> mp1,mp2;
	auto dfs1=[&](this auto&& self,int l,int r) -> int {
		if (l == r) return 0;
		if (l == r-1) return a[l]+a[r];
		if (mp1.count({l,r})) return mp1[{l,r}];
		
		int res=inf;
		for(int k=l;k<r;k++) {
			res=min(res,self(l,k)+self(k+1,r));
		}
		res+=pre[r]-pre[l-1];
		mp1[{l,r}]=res;
		return res;
	};
	auto dfs2=[&](this auto&& self,int l,int r) -> int {
		if (l == r) return 0;
		if (l == r-1) return a[l]+a[r];
		if (mp2.count({l,r})) return mp2[{l,r}];
		
		int res=0;
		for(int k=l;k<r;k++) {
			res=max(res,self(l,k)+self(k+1,r));
		}
		res+=pre[r]-pre[l-1];
		mp2[{l,r}]=res;
		return res;
	};
	
	int maxn=0,minn=inf;
	for(int i=1;i<=n;i++) {
		minn=min(minn,dfs1(i,i+n-1));
		maxn=max(maxn,dfs2(i,i+n-1));
	}
	
	cout<<minn<<"\n"<<maxn;
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









