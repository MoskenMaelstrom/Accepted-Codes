// Problem: P1168 中位数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1168
// Memory Limit: 128 MB
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
	vector<int> a;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		a.insert(upper_bound(a.begin(),a.end(),num),num);
		if (i%2 == 0) cout<<a[i/2]<<endl;
	}
}S

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









