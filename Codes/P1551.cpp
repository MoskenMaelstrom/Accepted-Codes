// Problem: 
//     P1551 亲戚
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1551
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int f[5005]={0};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,m,p;
	cin>>n>>m>>p;
	int a,b;
	for(int i=1;i<=n;i++) f[i]=i;
	while (m--){
		cin>>a>>b;
		while (f[a] != a) a=f[a];
		while (f[b] != b) b=f[b];
		f[a]=b;
	}
	while (p--){
		cin>>a>>b;
		while (f[a] != a) a=f[a];
		while (f[b] != b) b=f[b];
		if (a == b) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}



