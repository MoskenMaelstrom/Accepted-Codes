// Problem: E - Minimum Swap
// Contest: AtCoder - AtCoder Beginner Contest 436
// URL: https://atcoder.jp/contests/abc436/tasks/abc436_e
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
	for(int i=0;i<n;i++) {
		cin>>a[i];
		a[i]--;
	}
	
	int ans=0;
	vector<bool> mark(n);
	for(int i=0;i<n;i++) {
		int p=i;
		int cnt=0;
		while (!mark[p]) {
			mark[p]=1;
			cnt++;
			p=a[p];
		}
		ans+=cnt*(cnt-1)/2;
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







