#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int p=1e9+7;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector dp(n+1,vector<int>(m+1));
	for(int j=1;j<=m;j++) {
		int r=min(j,n);
		for(int i=1;i<=r;i++) {
			if (j-i == 0) dp[i][j]=1;
			else {
				for(int k=1;k<=i;k++) {
					dp[i][j]+=dp[k][j-i]*(i-k+1);
					dp[i][j]%=p;
				}
			}
		}
	}
	cout<<dp[n][m];
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







