// Problem: P2197 【模板】Nim 游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2197
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

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);	
	for(int i=0;i<n;i++) cin>>a[i];
	
	int ans=0;
	for(int i=0;i<n;i++) ans^=a[i];
	if (ans == 0) cout<<"No\n";
	else cout<<"Yes\n";
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









