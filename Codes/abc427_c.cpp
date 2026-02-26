// Problem: C - Bipartize
// Contest: AtCoder - Panasonic Programming Contest 2025（AtCoder Beginner Contest 427）
// URL: https://atcoder.jp/contests/abc427/tasks/abc427_c
// Memory Limit: 1024 MB
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
	int n,m;
	cin>>n>>m;
	vector<array<int,2>> edge(m);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		edge[i]={u,v};
	}
	
	int ans=m;
	for(int bit=0;bit<1<<n;bit++) {
		int cnt=0;
		for(auto [u,v] : edge) {
			if (((bit>>u)&1) == ((bit>>v)&1)) cnt++;
		}
		ans=min(ans,cnt);
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









