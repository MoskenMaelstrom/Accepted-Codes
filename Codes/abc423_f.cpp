// Problem: F - Loud Cicada
// Contest: AtCoder - AtCoder Beginner Contest 423
// URL: https://atcoder.jp/contests/abc423/tasks/abc423_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n,m,y;
	cin>>n>>m>>y;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	vector<int> f(1<<n);
	f[0]=y;
	for(int b=1;b<(1<<n);b++) {
		int l=1;
		for(int i=0;i<n;i++) {
			if ((b>>i)&1) {
				int g=gcd(l,a[i]);
				if (l/g > y/a[i]) l=y+1;
				else l=(l/g)*a[i];
			}
			if (l > y) break;
		}
		f[b]=y/l;
	}
	
	for(int i=0;i<n;i++) {
		for(int b=0;b<(1<<n);b++) {
			if (((b>>i)&1) == 0) f[b]-=f[b|(1<<i)];
		}
	}
	
	int ans=0;
	for(int b=0;b<(1<<n);b++) {
		if (__builtin_popcountll(b) == m) ans+=f[b];
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









