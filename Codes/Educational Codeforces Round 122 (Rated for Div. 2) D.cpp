// Problem: D. Make Them Equal
// Contest: Codeforces - Educational Codeforces Round 122 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1633/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int N=1000;
int dp[N+1];
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>b[i];
	vector<int> c(n);
	for(int i=0;i<n;i++) cin>>c[i];
	
	k=min(k,15*n);
	vector<int> f(k+1);
	for(int i=0;i<n;i++) {
		for(int j=k;j>=dp[b[i]];j--) {
			f[j]=max(f[j],f[j-dp[b[i]]]+c[i]);
		}
	}
	cout<<f[k]<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	fill(dp,dp+N+1,1e18);
	dp[1]=0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=i;j++) {
			if (i+i/j <= N) dp[i+i/j]=min(dp[i+i/j],dp[i]+1);
		}
	}
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







