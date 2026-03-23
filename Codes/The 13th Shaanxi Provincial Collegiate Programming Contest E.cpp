// Problem: E. Printer
// Contest: Codeforces - The 13th Shaanxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105891/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

int dp[21][1<<20];
const int inf=1e18;
void solve()
{
	int n,m,t;
	cin>>n>>m>>t;
	string s;
	cin>>s;
	vector<int> a(n+1);
	for(int i=0;i<n;i++) a[i]=s[i]-'a';
	vector cost(m,vector<int>(m));
	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++) {
			cin>>cost[i][j];
		}
	}
	
	for(int mask=(1<<n)-2;mask>=0;mask--) {
		for(int i=0;i<=n;i++) {
			if (i == n and mask == 0 or (mask>>i&1)) {
				int tot=__builtin_popcount(mask);
				int lst=__builtin_popcount(mask&((1<<(i+1))-1));
				int c=0;
				int ans=inf;
				for(int j=0;j<n;j++) {
					if (mask>>j&1) c++;
					else ans=min(ans,dp[j][mask|(1<<j)]+cost[a[i]][a[j]]+t*abs(c-lst));
				}
				dp[i][mask]=ans;
			}
		}
	}
	cout<<dp[n][0]+t*n;
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







