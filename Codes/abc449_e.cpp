// Problem: E - A += v
// Contest: AtCoder - AtCoder Beginner Contest 449
// URL: https://atcoder.jp/contests/abc449/tasks/abc449_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1),b(n+1);
	vector<int> cnt(m+1);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=m*(cnt[a[i]]++)+a[i];
	}
	sort(b.begin()+1,b.end());
	for(int i=1;i<=n;i++) b[i]-=i;
	int q;
	cin>>q;
	while (q--) {
		int k;
		cin>>k;
		if (k <= n) {cout<<a[k]<<"\n";}
		else {
			int t=lower_bound(b.begin()+1,b.end(),k-n)-b.begin()-1;
			cout<<(k-n+t-1)%m+1<<"\n";
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







