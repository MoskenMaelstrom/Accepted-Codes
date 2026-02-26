// Problem: C - ~
// Contest: AtCoder - Panasonic Programming Contest 2025（AtCoder Beginner Contest 406）
// URL: https://atcoder.jp/contests/abc406/tasks/abc406_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> c(n+1);
	for(int i=1;i<=n;i++) {
		c[i]=a[i]-a[i-1];
	}
	c[1]=0;
	vector<int> cl(n+1);
	int cnt=0;
	for(int i=1;i<=n;i++) {
		cl[i]=cnt;
		if (c[i]>0) cnt++;
		else cnt=0;
	}
	vector<int> cr(n+1);
	cnt=0;
	for(int i=n;i>=1;i--) {
		cr[i]=cnt;
		if (c[i]>0) cnt++;
		else cnt=0;
	}
	vector<int> cl2(n+1);
	cnt=0;
	for(int i=1;i<=n;i++) {
		cl2[i]=cnt;
		if (c[i]<0) cnt++;
		else cnt=0;
	}
	vector<int> cr2(n+1);
	cnt=0;
	for(int i=n;i>=1;i--) {
		cr2[i]=cnt;
		if (c[i]<0) cnt++;
		else cnt=0;
	}
	// for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=n;i++) cout<<cl[i]<<" ";
	// cout<<endl;
	// for(int i=1;i<=n;i++) cout<<cr[i]<<" ";
	// cout<<endl;
	int ans=0;
	for(int i=2;i<=n-2;i++) {
		if (c[i] > 0 and cr2[i] > 0 and i+cr2[i] != n) {
			ans+=(1+cl[i])*(1+cr[i+cr2[i]+1]);
		}
		// if (c[i] < 0 and cr[i] > 0 and i+cr[i] != n) {
			// ans+=(cl2[i]+1)*(cr2[i+cr[i]+1]+1);
		// }
	}
	cout<<ans<<endl;
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









