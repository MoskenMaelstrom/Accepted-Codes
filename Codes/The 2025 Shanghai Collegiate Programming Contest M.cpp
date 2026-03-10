// Problem: M. 魔法使考核
// Contest: Codeforces - The 2025 Shanghai Collegiate Programming Contest
// URL: https://codeforces.com/gym/105992/problem/M
// Memory Limit: 512 MB
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
	int n,x,y;
	cin>>n>>x>>y;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=1e18;
	for(int i=0;i<=30;i++) {
		i128 cnt=0;
		for(int j=0;j<n;j++) cnt+=__builtin_popcount(a[j]&((1<<i)-1))+(a[j]>>i);
		ans=min((i128)(i*y+cnt*x),(i128)ans);
	}
	cout<<ans<<"\n";
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







