// Problem: 
//     P2036 [COCI2008-2009 #2] PERKET
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2036
// Memory Limit: 32 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int MAX=1e11;
int n,mincha=MAX;
int suma=1,sumb=0;
int a[20],b[20];
void dfs(int x)
{
	if (x == n) return;
	//要x
	suma*=a[x];
	sumb+=b[x];
	mincha=min(mincha,abs(suma-sumb));
	dfs(x+1);
	//不要x
	suma/=a[x];
	sumb-=b[x];
	dfs(x+1);
}
signed main()
{
	cin>>n;	
	rep(i,n) cin>>a[i]>>b[i];
	
	dfs(0);
	cout<<mincha;
	return 0;
}









