// Problem: B - Nearest Taller
// Contest: AtCoder - AtCoder Beginner Contest 433
// URL: https://atcoder.jp/contests/abc433/tasks/abc433_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++) {
		int res=-1;
		for(int j=i-1;j>=0;j--) {
			if (a[j] > a[i]) {res=j+1;break;}
		}
		cout<<res<<"\n";
	}
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







