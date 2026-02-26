// Problem: B. Wishing Cards
// Contest: Codeforces - Codeforces Round 1069 (Div. 1)
// URL: https://codeforces.com/contest/2174/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

const int inf=1e18;
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> pos(k+1,inf);
	for(int i=n;i>=1;i--) pos[a[i]]=i;
	for(int i=k-1;i>=1;i--) pos[i]=min(pos[i],pos[i+1]);
	
	vector dp(k+1,vector<int>(k+1));
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=i;j++) {
			if (pos[j] == inf) continue;
			for(int w=0;w<=i-j;w++) {
				dp[i][j]=max(dp[i][j],dp[i-j][w]+(n-pos[j]+1)*(j-w));
			}
		}
	}
	int ans=0;
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=k;j++) {
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<"\n";
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







