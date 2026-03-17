// Problem: C. Dima and Salad
// Contest: Codeforces - Codeforces Round 214 (Div. 2)
// URL: https://codeforces.com/problemset/problem/366/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int inf=1e18;
const int N=1e5;
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i],b[i]=a[i]-k*b[i];
	
	int ans=0;
	vector<int> dp(2*N+1,-inf);
	dp[N]=0;
	for(int i=0;i<n;i++) {
		if (b[i] >= 0) {
			for(int j=2*N;j>=b[i];j--) {
				dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
			}
		}
		else {
			for(int j=0;j<=b[i]+2*N;j++) {
				dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
			}
		}
	}
	if (dp[N] == 0) cout<<"-1";
	else cout<<dp[N];
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







