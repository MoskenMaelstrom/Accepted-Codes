// Problem: 
//     P3817 小A的糖果
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3817
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int n,x,cha,ans=0;
	cin>>n>>x;
	vector<int> a(n+5);
	rep(i,n)cin>>a[i];
	rep(i,n-1)
	{
		if (a[i]+a[i+1]>x){
			cha=a[i+1]+a[i]-x;
			ans+=cha;
			if(a[i+1]-cha>=0)
				a[i+1]-=cha;
			else {
				a[i+1]=0;
				a[i]-=cha-a[i+1];
			}
		}
	}
	if(n==1) ans= a[0]<=x ? 0 : a[0]-x;
	cout<<ans;
	return 0;
}