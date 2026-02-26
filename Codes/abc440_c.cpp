// Problem: C - Striped Horse
// Contest: AtCoder - AtCoder Beginner Contest 440
// URL: https://atcoder.jp/contests/abc440/tasks/abc440_c
// Memory Limit: 1024 MB
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
	int n,w;
	cin>>n>>w;
	vector<int> a(n+1+2*w);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> pre(n+1+2*w);
	for(int i=1;i<=w;i++) pre[i]+=pre[i-1]+a[i];
	for(int i=w+1;i<=n+w;i++) pre[i]+=pre[i-1]-a[i-w]+a[i];
	
	auto calc=[&](int p) -> int {
		int res=0;
		for(int i=p;i<=n+w;i+=2*w) res+=pre[i];
		return res;
	};
	
	int ans=inf;
	for(int i=0;i<2*w;i++) {
		ans=min(ans,calc(i));
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







