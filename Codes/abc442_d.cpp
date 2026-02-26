// Problem: D - Swap and Range Sum
// Contest: AtCoder - JPRS Programming Contest 2026#1 (AtCoder Beginner Contest 442)
// URL: https://atcoder.jp/contests/abc442/tasks/abc442_d
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
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	while (q--) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int x;
			cin>>x;
			pre[x]+=a[x+1]-a[x];
			swap(a[x],a[x+1]);
		}
		else {
			int l,r;
			cin>>l>>r;
			cout<<pre[r]-pre[l-1]<<"\n";
		}
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







