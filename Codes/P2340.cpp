// Problem: P2340 [USACO03FALL] Cow Exhibition G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2340
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

const int N=5e5;
const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	
	vector<int> dp(2*N+1,-inf);
	dp[N]=0;
	for(int i=1;i<=n;i++) {
		if (a[i] >= 0) {
			for(int j=2*N;j>=a[i];j--) {
				dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
			}
		}
		else {
			for(int j=0;j<=2*N+a[i];j++) {
				dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
			}
		}
	}
	
	int ans=0;
	for(int j=N;j<=2*N;j++) {
		if (dp[j] > 0) ans=max(ans,dp[j]+j-N);
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








