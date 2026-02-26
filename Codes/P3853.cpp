// Problem: 
//     P3853 [TJOI2007] 路标设置
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3853
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
	int l,n,k,temp;
	cin>>l>>n>>k;
	vector<int> a(n+5);
	rep(i,n) cin>>a[i];
	
	vector<int> cha(n+5);
	rep(i,n-1) cha[i]=a[i+1]-a[i];	//cha的len为n-1
	int q=0,p=l,mid,ansmid,sum;
	while (q<=p)
	{
		sum=0;
		mid=(q+p)/2;
		if (q+p == 1) mid=1;
		if (mid == 0) break;
		rep(i,n-1)
			if (cha[i] > mid) sum+=(cha[i]-1)/mid;
		if (sum <= k){					//合格，减小mid
			ansmid=mid;
			p=mid-1;
		}
		else q=mid+1;				//不合格，增大mid
	}
	cout<<ansmid;
	return 0;
}










