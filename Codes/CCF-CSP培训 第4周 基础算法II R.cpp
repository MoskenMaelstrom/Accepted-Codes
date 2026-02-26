// Problem: R - Perfect
// Contest: Virtual Judge - CCF-CSP培训 第4周 基础算法II
// URL: https://vjudge.net/contest/751877#problem/R
// Memory Limit: 1024 MB
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
	int n,m,k;
	cin>>n>>m>>k;
	vector b(n+1,vector<int>(m+1));
	vector<int> cnt(n+1);
	for(int i=0;i<k;i++) {
		int x,y;
		cin>>x>>y;
		if (b[x][y]) continue;
		cnt[x]++;
		b[x][y]=1;
		if (cnt[x] == m) cout<<x<<" ";
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









