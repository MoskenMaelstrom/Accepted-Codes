#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int p=1e6+7;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(auto &e1 : a) cin>>e1;
	
	vector dp(n,vector<int>(m+1));//dp[i][j]表示进行到第i个时,总和为j的数量
	for(int j=0;j<=a[0];j++) {
		dp[0][j]=1;
	}
	//dp[i][j] = dp[i-1][j]+dp[i-1][j-1]+ ... +dp[i-1][j-(a[i])];
	for(int i=1;i<n;i++) {
		for(int j=0;j<=m;j++) {
			for(int k=0;k<=min(j,a[i]);k++) {
				dp[i][j]+=dp[i-1][j-k];
				dp[i][j]%=p;
			}
		}
	}
	
	cout<<dp[n-1][m];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









