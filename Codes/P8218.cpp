// Problem: 
//     P8218 【深进1.例1】求区间和
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8218
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int n;
	cin>>n;
	vector<int> a(n+5,0);
	vector<int> pre(n+5,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int m;
	cin>>m;
	for(int i=1;i<=m;i++) {
		int l,r;
		cin>>l>>r;
		cout<<pre[r]-pre[l-1]<<endl;
	}
	return 0;
}