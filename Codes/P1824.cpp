// Problem: 
//     P1824 进击的奶牛
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1824
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
	int n,m;
	cin>>n>>m;
	vector<int> a(n+5);
	rep(i,n) cin>>a[i];
	sort(a.begin(),a.begin()+n);
	int maxdis=(a[n-1]-a[0])/(m-1);	//maxdis为最优情况两头牛的间距
	int q=0,p=maxdis,mid;			//对maxdis进行二分查找
	int sum,room,ansmid;
	vector<int> cha(n+5);
	rep(i,n-1) cha[i]=a[i+1]-a[i];	//cha的长度为n-1
	while (q<=p)
	{
		sum=0;
		room=0;				//room代表安置的隔间个数-1
		mid=(q+p)/2;
		rep(i,n-1){			//遍历cha
			sum+=cha[i];
			if(sum>=mid){	//合格
				room++;
				sum=0;
			}
		}
		if (room>=m-1){		//合格，增大间距
			ansmid=mid;
			q=mid+1;
		}
		else p=mid-1;
	}
	cout<<ansmid;
	return 0;
}










