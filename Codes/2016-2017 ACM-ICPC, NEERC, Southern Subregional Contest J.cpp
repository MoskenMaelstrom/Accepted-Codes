// Problem: J. Bottles
// Contest: Codeforces - 2016-2017 ACM-ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/730/J
// Memory Limit: 512 MB
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
	int n;
	cin>>n;
	vector<array<int,2>> vec(n+1);
	int sum=0;
	for(int i=1;i<=n;i++) cin>>vec[i][0],sum+=vec[i][0];
	for(int i=1;i<=n;i++) cin>>vec[i][1];
	sort(vec.begin()+1,vec.end(),[&](array<int,2> &A,array<int,2> &B){
		return A[1] > B[1];
	});
	
	int k=0,cnt=0;
	for(int i=1;i<=n;i++) {
		if (cnt >= sum) break;
		k++,cnt+=vec[i][1];
	}
	
	int T=0;
	for(int i=1;i<=n;i++) T+=vec[i][1];
	vector dp(n+1,vector<int>(T+1,-1));
	dp[0][0]=0;
	for(int i=1;i<=n;i++) {
		for(int j=i;j>=1;j--) {
			for(int c=T;c>=vec[i][1];c--) {
				if (dp[j-1][c-vec[i][1]] < 0) continue;
				dp[j][c]=max(dp[j][c],dp[j-1][c-vec[i][1]]+vec[i][0]);
			}
		}
	}
	cout<<k<<" "<<sum-*max_element(dp[k].begin()+sum,dp[k].end());
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







