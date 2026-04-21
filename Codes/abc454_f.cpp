// Problem: F - Make it Palindrome 2
// Contest: AtCoder - Keysight Technologies Programming Contest（AtCoder Beginner Contest 454）
// URL: https://atcoder.jp/contests/abc454/tasks/abc454_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n+2);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> d; 
	for(int i=1;i<=n/2+1;i++) {
		if (i*2 == n+2) d.push_back((a[i]-a[i-1]+m)%m);
		else d.push_back((a[i]-a[i-1]+a[n-i+2]-a[n-i+1]+2*m)%m); 
	}
	
	int sum=accumulate(d.begin(),d.end(),0ll);
	// for(auto e1 : d) cout<<e1<<" ";
	// cout<<endl;
	ranges::sort(d);
	int ans=0;
	for(int i=0;i<d.size()-sum/m;i++) ans+=d[i];
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







