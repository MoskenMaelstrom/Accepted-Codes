// Problem: B - Tombola
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Christmas (AtCoder Beginner Contest 437)
// URL: https://atcoder.jp/contests/abc437/tasks/abc437_b
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
	int n,m,k;
	cin>>n>>m>>k;
	vector a(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}
	
	map<int,int> mp;
	for(int i=0;i<k;i++) {
		int num;
		cin>>num;
		mp[num]=1;
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		int cnt=0;
		for(int j=0;j<m;j++) {
			if (mp.count(a[i][j])) cnt++;
		}
		ans=max(ans,cnt);
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







