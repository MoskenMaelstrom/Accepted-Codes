// Problem: 
//     P1892 [BOI2003] 团伙
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1892
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int f[2005];
struct dui{
	char opt;
	int a,b;
}p[5005];
int fin1(int x)
{
	if (f[x] != x) f[x]=fin1(f[x]);
	return f[x];
}
int fin(int x)
{
	while (f[x] != x) x=f[x];
	return x;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	rep(i,2*n) f[i]=i;//初始化，i+n代表i的敌人，同一队的人有共同的敌人
	rep(i,m) cin>>p[i].opt>>p[i].a>>p[i].b;
	
	rep(i,m) if (p[i].opt == 'F') f[fin(p[i].a)]=fin(p[i].b);//把朋友联系在一起
	rep(i,m){
		if (p[i].opt == 'E') {
			f[fin(p[i].a+n)]=fin(p[i].b);
			f[fin(p[i].b+n)]=fin(p[i].a);	
		}
	}
	int ans=0;
	rep(i,n){
		if (f[i] == i) ans++;
	}
	cout<<ans;
	return 0;
}






