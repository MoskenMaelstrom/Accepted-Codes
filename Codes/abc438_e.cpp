// Problem: E - Heavy Buckets
// Contest: AtCoder - AtCoder Beginner Contest 438
// URL: https://atcoder.jp/contests/abc438/tasks/abc438_e
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector p(32,vector<int>(n+1));
	vector sum(32,vector<int>(n+1));
	
	for(int i=1;i<=n;i++) {
		p[0][i]=a[i];
		sum[0][i]=i;
	}
	
	for(int b=1;b<32;b++) {
		for(int i=1;i<=n;i++) {
			int mid=p[b-1][i];
			p[b][i]=p[b-1][mid];
			sum[b][i]=sum[b-1][i]+sum[b-1][mid];
		}
	}
	
	while (q--) {
		int t,id;
		cin>>t>>id;
		
		int cur=0;
		for(int b=0;b<32;b++) {
			if ((t>>b)&1) {
				cur+=sum[b][id];
				id=p[b][id];
			}
		}
		cout<<cur<<"\n";
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







