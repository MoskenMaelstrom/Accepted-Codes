// Problem: E - Kite
// Contest: AtCoder - AtCoder Beginner Contest 439
// URL: https://atcoder.jp/contests/abc439/tasks/abc439_e
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
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	
	ranges::sort(a,[](const array<int,2>& x,const array<int,2>& y) {
		if (x[0] != y[0]) return x[0] < y[0];
		else return x[1] > y[1];
	});
	vector<int> vec;
	for(int i=0;i<n;i++) {
		auto it=lower_bound(vec.begin(),vec.end(),a[i][1]);
		if (it == vec.end()) vec.push_back(a[i][1]);
		else *it=a[i][1];
	}
	cout<<vec.size();
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







