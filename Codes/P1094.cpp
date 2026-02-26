// Problem: 
//     P1094 [NOIP2007 普及组] 纪念品分组
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1094
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int w,n,ans=0;
	cin>>w>>n;
	int tail=n-1;
	vector<int> a(n+5);
	vector<bool> flag(n+5,0);
	rep(i,n)cin>>a[i];
	
	sort(a.begin(),a.begin()+n);
	for(int i=0;i<n;i++){
		if (i>=tail)break;
		while (tail>i){
			if (a[i]+a[tail]<=w){
				flag[i]=1;
				flag[tail--]=1;
				ans++;
				break;
			}
			tail--;
		}
	}
	rep(i,n)if(!flag[i])ans++;
	cout<<ans;
	return 0;
}