// Problem: B. Marble Council
// Contest: Codeforces - Codeforces Round 1064 (Div. 1)
// URL: https://codeforces.com/contest/2165/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1),cnt(n+1);
	int maxn=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		cnt[a[i]]++;
		maxn=max(maxn,cnt[a[i]]);
	}
	
	vector<int> dp(n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=n;j>=cnt[i];j--) {
			dp[j]+=cnt[i]*dp[j-cnt[i]];
			dp[j]%=p;
		}
	}
	int ans=0;
	for(int j=maxn;j<=n;j++) ans+=dp[j],ans%=p;
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







