// Problem: 
//     P7072 [CSP-J2020] 直播获奖
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7072
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
int tong[605]={0};
signed main()
{
	int n,w;
	cin>>n>>w;
	for(int i=1;i<=n;i++) {
		int a;
		cin>>a;
		tong[a]++;
		int sum=0;//统计人数
		for(int j=600;j>=0;j--) {
			sum+=tong[j];
			if (sum >= max(1,i*w/100)) {cout<<j<<" ";break;}
		}
	}
	return 0;
}








