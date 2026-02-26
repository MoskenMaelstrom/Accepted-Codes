// Problem: B - Bird Watching
// Contest: AtCoder - Ｓｋｙ Inc, Programming Contest 2025 (AtCoder Beginner Contest 434)
// URL: https://atcoder.jp/contests/abc434/tasks/abc434_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(m+1);
	vector<int> cnt(m+1);
	for(int i=0;i<n;i++) {
		int k,w;
		cin>>k>>w;
		a[k]+=w;
		cnt[k]++;
	}
	for(int i=1;i<=m;i++) {
		cout<<fixed<<setprecision(10)<<(double)a[i]/cnt[i]<<"\n";
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







