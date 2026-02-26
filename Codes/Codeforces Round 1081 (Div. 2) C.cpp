// Problem: C. All-in-one Gun
// Contest: Codeforces - Codeforces Round 1081 (Div. 2)
// URL: https://codeforces.com/contest/2192/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n,h,k;
	cin>>n>>h>>k;
	vector<int> a(n+1);
	vector<int> pre(n+1,inf);
	vector<int> suf(n+1);
	vector<int> sum(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) pre[i]=min(pre[i-1],a[i]);
	for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
	suf[n]=a[n];
	for(int i=n-1;i>=1;i--) suf[i]=max(suf[i+1],a[i]);
	
	int ans=inf;
	for(int i=1;i<=n;i++) {
		int d=sum[i];
		if (i < n) d=max(d,sum[i]-pre[i]+suf[i+1]);
		ans=min(ans,(max(0ll,h-d)+sum[n]-1)/sum[n]*(n+k)+i);
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







