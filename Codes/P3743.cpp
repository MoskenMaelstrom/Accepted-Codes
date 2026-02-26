// Problem: 
//     P3743 小鸟的设备
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3743
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const double cha=1e-5;
signed main()
{
	int n,p;
	cin>>n>>p;
	vector<int> a(n+5);	//存单位耗能
	vector<int> b(n+5);	//存目前电量
	rep(i,n) cin>>a[i]>>b[i];
	//-1特判
	int suma=0;
	rep(i,n) suma+=a[i];
	if (suma <= p) {
		cout<<-1;
		return 0;
	}
	//
	double L=0,R=100000000000,mid,consume,cdb,ansmid,rest;//用mid代表时间，然后再分配p*mid，如果够分配就增大mid
	bool flag;
	while (L-R<=-cha)
	{
		flag=1;
		mid=(L+R)/2;
		cdb=mid*p;						//充电宝剩余电量
		rep(i,n){						//对每一个设备进行耗能计算与充电计算，目的是返回一个flag
			rest=b[i];
			consume=mid*a[i];			//该设备mid时间的耗电量
			//设备不需要充电宝的话就直接过了
			if (consume >= rest) {		//设备需要充电宝
				consume-=rest;
				if (cdb>consume) cdb-=consume;
				else {flag=0;break;}	//cdb也没电了
			}
		}
		if (flag) {
			ansmid=mid;
			L=mid+cha;
		}
		else R=mid-cha;
	}
	
	cout<<ansmid;
	return 0;
}













