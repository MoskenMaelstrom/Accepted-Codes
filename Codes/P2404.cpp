// Problem: 
//     P2404 自然数的拆分问题
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2404
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n;
int a[10];
void dfs(int num,int deep)
{
	if (num == 0) {
		rep(i,deep-1) cout<<a[i]<<"+";
		cout<<a[deep-1]<<endl;
		return;
	}
	for(int i=a[deep-1];i<=num;i++){
		a[deep]=i;
		dfs(num-i,deep+1);
	}
}	
signed main()
{
	cin>>n;
	for(int i=1;i<=n/2;i++) {
		a[0]=i;
		dfs(n-i,1);
	}
	return 0;
}





