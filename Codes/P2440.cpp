// Problem: 
//     P2440 木材加工
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2440
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
	int n,k,maxlen=0;
	cin>>n>>k;
	vector<int> a(n+5);
	rep(i,n) cin>>a[i];
	sort(a.begin(),a.begin()+n);//升序
	rep(i,n) maxlen+=a[i];
	maxlen/=k;					//maxlen代表最优情况长度
	int q=0,p=maxlen,mid,sum,anslen=0;
	while (q<=p)
	{
		sum=0;
		mid=(q+p)/2;
		if (q+p == 1) mid=1;
		if (mid == 0) break;
		rep(i,n) sum+=a[i]/mid;	//遍历a
		if (sum >= k){
			q=mid+1;
			anslen=mid;
		}
		else{
			p=mid-1;
		}
	}
	cout<<anslen;
	return 0;
}













