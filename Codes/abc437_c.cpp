// Problem: C - Reindeer and Sleigh 2
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Christmas (AtCoder Beginner Contest 437)
// URL: https://atcoder.jp/contests/abc437/tasks/abc437_c
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
	vector<array<int,3>> a(n);
	int sum=0;
	for(int i=0;i<n;i++) {
		cin>>a[i][1]>>a[i][2];
		a[i][0]=a[i][2]+a[i][1];
		sum+=a[i][2];
	}
	
	ranges::sort(a);
	int ans=0;
	for(int i=0;i<n;i++) {
		sum-=a[i][0];
		if (sum >= 0) ans++;
		else break;
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







