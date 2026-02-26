// Problem: 
//     P1873 [COCI 2011/2012 #5] EKO / 砍树
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1873
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int n,m,mid,sum,ansmid;
	cin>>n>>m;
	vector<int> a(n+5);
	rep(i,n) cin>>a[i];
	sort(a.begin(),a.begin()+n);
	int q=0,p=a[n-1];//确定树的上界
	while (q<=p)
	{
		sum=0;
		mid=(q+p)/2;
		rep(i,n)
			if (a[i]>mid) sum+=a[i]-mid;
		if (sum>=m){		//合格,继续抬高
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








