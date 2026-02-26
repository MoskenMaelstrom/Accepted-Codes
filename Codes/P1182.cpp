// Problem: 
//     P1182 数列分段 Section II
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1182
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
bool cmp(int a1,int a2)
{
	return a1>a2;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n+5);
	rep(i,n) cin>>a[i];
	int q=0,p=0,ansmid,mid;
	rep(i,n) p+=a[i];
	rep(i,n) q=max(q,a[i]);
	while (q<=p)
	{
		mid=(q+p)/2;
		int duan=1,sum=0;
		rep(i,n){
			if (sum+a[i] <= mid) sum+=a[i];
			else {
				sum=0;
				sum+=a[i];
				duan++;
			}
		}
		if (duan <= m){		//合格
			ansmid=mid;
			p=mid-1;
		}
		else q=mid+1;
	}	
	cout<<ansmid;
	return 0;
}









