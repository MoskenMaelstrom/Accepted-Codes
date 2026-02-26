// Problem: C. First or Second
// Contest: Codeforces - Good Bye 2025
// URL: https://codeforces.com/contest/2178/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int ans=-1e18;
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) pre[i]+=pre[i-1]+a[i];
	
	vector<int> dp0(n+1);
	vector<int> dp1(n+1);
	dp0[1]=a[1];
	int c=2*a[1];
	for(int i=2;i<=n;i++) {
		dp1[i]=dp0[i-1];
        dp0[i]=max(c-pre[i],dp0[i-1]+a[i]);
        c=max(c,dp1[i]+a[i]+pre[i]);
	}
	
    for(int i=1;i<=n;i++) ans=max(ans,dp1[i]+pre[i]-pre[n]);
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







