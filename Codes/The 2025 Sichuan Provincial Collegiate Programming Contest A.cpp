// Problem: A. Minimum Product
// Contest: Codeforces - The 2025 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105949/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<array<int,4>> edge(m);
	for(int i=0;i<m;i++) {
		int u,v,a,b;
		cin>>u>>v>>a>>b;
		u--,v--;
		edge[i]={u,v,a,b};
	}

	vector dp(200*n+1,vector<int>(n,inf));
	dp[0][0]=0;
	for(int t=0;t<=200*n;t++) {
		for(int i=0;i<m;i++) {
			auto [u,v,a,b]=edge[i];
			if (dp[t][u] != -1 and t+a <= 200*n) {
				dp[t+a][v]=min(dp[t+a][v],dp[t][u]+b);
			}
		}
	}
	
	int ans=inf;
	int a=inf,b=inf;
	for(int t=0;t<=200*n;t++) {
		if (dp[t][n-1] != inf and ans > t*dp[t][n-1]) {
			ans=t*dp[t][n-1];
			a=t;
			b=dp[t][n-1];
		}
	}
	cout<<a<<" "<<b<<"\n";
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







