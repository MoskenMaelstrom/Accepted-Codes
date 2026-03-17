// Problem: D. Pawn
// Contest: Codeforces - Codeforces Beta Round 40 (Div. 2)
// URL: https://codeforces.com/problemset/problem/41/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	k++;
	vector a(n+2,vector<int>(m+2));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			char c;
			cin>>c;
			a[i][j]=c-'0';
		}
	}
	
	vector dp(n+2,vector<vector<int>>(m+1,vector<int>(k,-1)));
	for(int j=1;j<=m;j++) dp[n+1][j][0]=0;
	for(int i=n;i>=1;i--) {
		for(int j=1;j<=m;j++) {
			for(int l=0;l<k;l++) {
				if (j != 1 and dp[i+1][j-1][l] != -1) {
					dp[i][j][(l+a[i][j])%k]=max(dp[i][j][(l+a[i][j])%k],dp[i+1][j-1][l]+a[i][j]);
				}
				if (j != m and dp[i+1][j+1][l] != -1) {
					dp[i][j][(l+a[i][j])%k]=max(dp[i][j][(l+a[i][j])%k],dp[i+1][j+1][l]+a[i][j]);
				}
			}
		}
	}
	
	int ans=-1,id=-1;
	for(int j=1;j<=m;j++) {
		if (ans < dp[1][j][0]) ans=dp[1][j][0],id=j;
	}
	if (ans == -1) cout<<"-1";
	else {
		cout<<ans<<"\n";
		string s;
		int i=1,j=id,l=0;
		while (i != n) {
			if (j != 1 and dp[i][j][l]-a[i][j] == dp[i+1][j-1][((l-a[i][j])%k+k)%k]) {
				s+="R";
				l=(dp[i][j][l]-a[i][j])%k;
				i++;
				j--;
			}
			else {
				s+="L";
				l=(dp[i][j][l]-a[i][j])%k;
				i++;
				j++;
			}
		}
		
		cout<<j<<"\n";
		ranges::reverse(s);
		cout<<s;
	}
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







