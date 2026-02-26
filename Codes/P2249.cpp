// Problem: 
//     P2249 【深基13.例1】查找
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2249
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int n,m,pos;
	cin>>n>>m;
	vector<int> a(n+5);
	vector<int> b(m+5);
	rep(i,n) cin>>a[i];
	rep(i,m) cin>>b[i];
	rep(i,m){
		pos=lower_bound(a.begin(),a.begin()+n,b[i])-a.begin();
		if (pos == n or a[pos] != b[i]) cout<<"-1 ";
		else cout<<pos+1<<" ";
	}
	return 0;
}