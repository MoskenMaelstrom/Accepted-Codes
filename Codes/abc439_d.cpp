// Problem: D - Kadomatsu Subsequence
// Contest: AtCoder - AtCoder Beginner Contest 439
// URL: https://atcoder.jp/contests/abc439/tasks/abc439_d
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
	int n;
	cin>>n;
	vector<int> a(n);
	map<int,int> mp;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		mp[a[i]]++;
	}
	auto mp1=mp;
	int ans=0;
	for(int i=0;i<n;i++) {
		mp[a[i]]--;
		if (a[i]%5 != 0) continue;
		int k=a[i]/5;
		int c1=mp[k*7];
		int c2=mp[k*3];
		ans+=c1*c2;
	}
	
	mp=mp1;
	for(int i=n-1;i>=0;i--) {
		mp[a[i]]--;
		if (a[i]%5 != 0) continue;
		int k=a[i]/5;
		int c1=mp[k*7];
		int c2=mp[k*3];
		ans+=c1*c2;
	}
	cout<<ans<<"\n";
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







