// Problem: 
//     P4715 【深基16.例1】淘汰赛
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4715
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int k,n=1;
	cin>>k;
	while (k--) n*=2;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int maxl=0,maxr=0;
	int ansl,ansr;
	for(int i=0;i<n/2;i++)
		if (maxl < a[i]) maxl=a[i],ansl=i+1;
	for (int i=n/2;i<n;i++) 
		if (maxr < a[i]) maxr=a[i],ansr=i+1;
	if (maxl < maxr) cout<<ansl;
	else cout<<ansr;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









