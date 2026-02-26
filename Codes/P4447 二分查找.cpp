// Problem: 
//     P4447 [AHOI2018初中组] 分组
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4447
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
	int n;
	cin>>n;
	vector<int> a(n+5);
	vector<int> sl(n+5,0);	//存实力，用二分查找O(logn)维护有序性
	vector<int> siz(n+5);	
	rep(i,n) cin>>a[i];
	sort(a.begin(),a.begin()+n);
	
	//思路：sl里面是升序的每组的实力max，其中实力相同的按照amount升序
	int len=0,pos;
	rep(i,n)	//O(nlogn)
	{//1 1 3 4 cin>>4
		pos=upper_bound(sl.begin(),sl.begin()+len,a[i]-1)-sl.begin();
		if (sl[pos-1] != a[i]-1){		 //pos-1指向的sl不合法
			siz[len]++;						//新建一个组，其mount初始化为1
			sl[len++]=a[i];					//初始化组中最大的sl为a[i]
		}
		else {							//pos-1指向的sl合法
			siz[pos-1]++;					//a[i]-1的位置的amount+1
			sl[pos-1]++;					//a[i]-1位置的sl变成a[i]
		}
	}
	
	int ans=100005;
	rep(i,len) ans=min(ans,siz[i]);
	cout<<ans;
	return 0;
}








