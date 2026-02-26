// Problem: 
//     P2678 [NOIP2015 提高组] 跳石头
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2678
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int l,n,m;//一共有n+1个间距，移走m个岩石，剩下n+1-m个间距
	cin>>l>>n>>m;
	if (n==0) {cout<<l;return 0;}
	vector<int> a(n+5);
	vector<int> cha(n+5);
	rep(i,n) cin>>a[i];
	int mindis=l/(n+1-m);//初始化最优的间距，并对其进行搜索
	cha[0]=a[0];
	cha[n]=l-a[n-1];
	for(int i=1;i<n;i++) cha[i]=a[i]-a[i-1];//cha有n+1项
	
	int q=0,p=mindis,mid,sum,stone,ansmid=mindis;
	while(q<=p)
	{
		sum=0;
		stone=0;
		mid=(q+p)/2;		//mid即目前查找的间距
		rep(i,n+1){			//遍历cha
			sum+=cha[i];
			if(sum>=mid) {stone++;sum=0;}
		}
		if (stone>=n-m+1){	//合格，增大间距
			ansmid=mid;
			q=mid+1;
		}
		else{
			p=mid-1;
		}
	}
	cout<<ansmid;
	return 0;
}









