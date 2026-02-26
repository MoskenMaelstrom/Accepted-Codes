// Problem: Sensei and Affection (affection)
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108307/E
// Memory Limit: 512 MB
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
// #define int long long
using namespace std;

const int inf=1e9;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	if (m == 1) {
		int x=*ranges::max_element(a);
		vector<int> b(n);
		for(int i=0;i<n;i++) b[i]=x-a[i];
		int ans=b[0];
		for(int i=1;i<n;i++) {
			if (b[i-1] < b[i]) ans+=b[i]-b[i-1];
		}
		cout<<ans<<'\n';
		return;
	}
	
	int ans=inf;
	int x=*ranges::min_element(a);
	int y=*ranges::max_element(a);
	for(int i=x;i<200;i++) {
		for(int j=y;j<200;j++) {
			// if (i > j) continue;
			vector<array<int,2>> dp(n,{inf,inf});
			dp[0][0]=i-a[0] >= 0 ? i-a[0] : inf;
			dp[0][1]=j-a[0];
			
			for(int k=1;k<n;k++) {
				if (i-a[k] >= 0) 
					dp[k][0]=min(dp[k-1][0]+max(0,a[k-1]-a[k]) , dp[k-1][1]+max(0,a[k-1]-a[k]+i-j));
				dp[k][1]=min(dp[k-1][0]+max(0,a[k-1]-a[k]+j-i) , dp[k-1][1]+max(0,a[k-1]-a[k]));
			}
			
			ans=min({ans,dp[n-1][0],dp[n-1][1]});
		}
	}
	
	cout<<ans<<'\n';
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









