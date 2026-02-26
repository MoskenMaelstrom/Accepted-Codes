// Problem: AT_abc418_d [ABC418D] XNOR Operation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT_abc418_d
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=" "+s;
	vector<int> a(n+1),c0(n+1),c1(n+1);
	for(int i=1;i<=n;i++) {
		a[i]=a[i-1];
		if (s[i] == '0') a[i]++;
	}
	for(int i=1;i<=n;i++) {
		c0[i]=c0[i-1];
		c1[i]=c1[i-1];
		if (a[i]%2 == 0) c0[i]++;
		else c1[i]++;
	}
	
	int ans=0;
	for(int l=1;l<=n;l++) {
		if (a[l-1]%2 == 0) ans+=c0[n]-c0[l-1];
		else ans+=c1[n]-c1[l-1];
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









