// Problem: B2. Sub-RBS (Hard Version)
// Contest: Codeforces - Codeforces Round 1073 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2190/B2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
// #define int long long
#define ull unsigned long long
using namespace std;

const int p=998244353;
int dp[101][101][101][51];
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=" "+s;
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			for(int k=0;k<=n;k++) {
				for(int l=0;l<=n/2;l++) {
					dp[i][j][k][l]=-1;
				}
			}
		}
	}
	
	function<int(int,int,int,int)> dfs=[&](int i,int j,int k,int l) -> int {
		if (j < 0 or k < 0 or l < 0 or l > j/2 or k > j) return 0;
		if (i == 0 and j == 0 and k == 0 and l == 0) return 1;
		else if (i == 0) return 0;
		if (dp[i][j][k][l] != -1) return dp[i][j][k][l];
		
		int res=0;
		(res+=dfs(i-1,j,k,l))%=p;
		if (s[i] == '(') {
			if (l == 0) (res+=dfs(i-1,j-1,k-1,0))%=p;
			else (res+=dfs(i-1,j-1,k,l))%=p;
		}
		else (res+=dfs(i-1,j-1,k,l-1))%=p;
		
		return dp[i][j][k][l]=res;
	};
	
	long long ans=0;
	for(int j=6;j<=n;j+=2) {
		for(int k=1;k<=j/2-2;k++) {
			(ans+=1ll*dfs(n,j,k,j/2)*(j-2))%=p;
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






