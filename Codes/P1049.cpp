// Problem: P1049 [NOIP 2001 普及组] 装箱问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1049
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int v,n;
	cin>>v>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> dp(v+1);
	for(int i=0;i<n;i++) {
		for(int j=v;j>=a[i];j--) {
			dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
		}
	}
	cout<<v-dp[v];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









