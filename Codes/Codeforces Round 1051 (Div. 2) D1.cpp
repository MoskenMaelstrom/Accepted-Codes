// Problem: D1. Inversion Graph Coloring (Easy Version)
// Contest: Codeforces - Codeforces Round 1051 (Div. 2)
// URL: https://codeforces.com/contest/2143/problem/D1
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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

const int p=1e9+7;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector dp(n+1,vector<int>(n+1));//涂红的元素最后一个是i，...是j
	dp[0][0]=1;
	for(int i=1;i<=n;i++) {
		auto cur=dp;
		for(int j=0;j<=n;j++) {
			for(int k=0;k<=n;k++) {
				int val=dp[j][k];
				if (j == 0 or j <= a[i]) {
					cur[a[i]][k]+=val;
					cur[a[i]][k]%=p;
				}
				else if (k == 0 or k <= a[i]) {
					cur[j][a[i]]+=val;
					cur[j][a[i]]%=p;
				}
			}
		}
		dp=cur;
	}
	int ans=0;
	for(int j=0;j<=n;j++) {
		for(int k=0;k<=n;k++) {
			ans+=dp[j][k];
			ans%=p;
		}
	}
	cout<<ans<<endl;
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









