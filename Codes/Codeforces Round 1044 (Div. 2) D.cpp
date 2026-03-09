// Problem: D. Chicken Jockey
// Contest: Codeforces - Codeforces Round 1044 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2133/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> d(n);
	d[0]=a[0];
	d[1]=a[0]+a[1]-1;
	for(int i=2;i<n;i++) {
		d[i]=min(d[i-1]+a[i]-1,d[i-2]+a[i-1]+max(0ll,a[i]-i));
	}
	cout<<d[n-1]<<"\n";
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







