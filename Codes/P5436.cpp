// Problem: 
//     P5436 【XR-2】缘分
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5436
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n;
	cin>>n;
	if (n == 1) cout<<1<<endl;
	else cout<<n*(n-1)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}