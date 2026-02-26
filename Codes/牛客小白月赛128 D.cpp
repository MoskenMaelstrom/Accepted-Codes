// Problem: 进退的艺术
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/127265/D
// Memory Limit: 512 MB
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
	int n,m;
	cin>>n>>m;
	vector<array<int,2>> a(n+1);
	for(int i=1;i<=n;i++) {
		cin>>a[i][0];
		a[i][1]=i;
	}
	sort(a.begin()+1,a.end());
	
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) pre[i]+=pre[i-1]+a[i][0];
	vector<int> ans(n+1);
	for(int i=1;i<=n;i++) {
		auto p=upper_bound(a.begin()+1,a.end(),array<int,2>{m-a[i][0],(int)1e18})-a.begin();
		if (p <= i) ans[a[i][1]]=a[i][0]*(p-1)-(pre[n]-pre[p-1]-a[i][0]);
		else ans[a[i][1]]=a[i][0]*(p-1)-(pre[n]-pre[p-1])-a[i][0];
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
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







