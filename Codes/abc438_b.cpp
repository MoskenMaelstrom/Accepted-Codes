// Problem: B - Substring 2
// Contest: AtCoder - AtCoder Beginner Contest 438
// URL: https://atcoder.jp/contests/abc438/tasks/abc438_b
// Memory Limit: 1024 MB
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
	string s1,s2;
	cin>>s1>>s2;
	int ans=1e18;
	for(int i=0;i<=n-m;i++) {
		int sum=0;
		for(int j=i;j<i+m;j++) {
			if (s1[j] >= s2[j-i]) sum+=s1[j]-s2[j-i];
			else sum+=s1[j]-s2[j-i]+10;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
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







