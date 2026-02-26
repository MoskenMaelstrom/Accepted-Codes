// Problem: 权值计算
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120562/H
// Memory Limit: 2048 MB
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> pre(n,-1);
	map<int,int> mp;
	for(int i=0;i<n;i++) {
		if (mp.count(a[i])) pre[i]=mp[a[i]];
		mp[a[i]]=i;
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		ans+=(i-pre[i])*(n-i+1)*(n-i)/2;
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







