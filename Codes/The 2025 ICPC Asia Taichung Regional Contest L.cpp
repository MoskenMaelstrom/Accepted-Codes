// Problem: L. Maximum Color Segment
// Contest: Codeforces - 2025 ICPC Asia Taichung Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/problemset/problem/2172/L
// Memory Limit: 256 MB
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
	int n,m,k;
	cin>>n>>m>>k;
	string s;
	cin>>s;
	s=" "+s;
	
	int ans=0;
	vector<array<int,2>> dp(m+1,{0,0});
	for(int i=1;i<=k;i++) {
		for(int j=0;j<=m;j++) {
			dp[j][0]=max(dp[j][0],dp[j][1]);
			dp[j][1]=0;
		}
		for(int x=i;x<=n;x+=k) {
			vector<array<int,2>> ndp(m+1,{0,0});
			for(int j=0;j<=m;j++) {
				ndp[j][0]=max(dp[j][0]+(s[x-1] != s[x]),dp[j][1]+(s[x-1] == s[x]));
				if (j > 0 and x <= n-k+1) ndp[j][1]=max(dp[j-1][0]+(s[x-1] == s[x]),dp[j-1][1]+(s[x-1] != s[x]));
				ans=max(ndp[j][0],ndp[j][1]);
			}
			dp=ndp;
		}
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







