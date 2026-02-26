// Problem: 
//     P4995 跳跳！
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4995
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
	int n,ans=0;
	cin>>n;
	vector<int> a(n+5);
	rep(i,n)cin>>a[i];
	sort(a.begin(),a.begin()+n);
	int q=0,p=n-1,temp=0;
	bool flag=1;
	while (q<=p)
	{
		if (flag){
			ans+=pow(a[p--]-temp,2);
			temp=a[p+1];
		}
		else {
			ans+=pow(a[q++]-temp,2);
			temp=a[q-1];
		}
		flag=!flag;
	}
	cout<<ans;
	return 0;
}


