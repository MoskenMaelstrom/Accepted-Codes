// Problem: Blackboard
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/H
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> dp(n+1),pre(n+1);
	vector<int> c(32);
	dp[0]=1;
	for(int i=0,j=0;i<n;i++) {
		for(int k=0;k<32;k++) c[k]+=a[i]>>k&1;	
		while (*ranges::max_element(c) > 1) {
			for(int k=0;k<32;k++) c[k]-=a[j]>>k&1;
			j++;
		}
		pre[i+1]=(pre[i]+dp[i])%p;
		dp[i+1]=(pre[i+1]-pre[j])%p;
	}
	cout<<(dp[n]+p)%p<<"\n";
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







