// Problem: C. Customer Service
// Contest: Codeforces - Codeforces Round 1002 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2059/C#
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector a(n,vector<int>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}
	
	vector<int> b;
	for(int i=0;i<n;i++) {
		int cnt=0;
		for(int j=n-1;j>=0;j--) {
			if (a[i][j] == 1) cnt++;
			else break; 
		}
		b.push_back(cnt);
	}
	ranges::sort(b);
	int ans=0;
	for(int i=0;i<b.size();i++) {
		if (b[i] >= ans) ans++;
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









