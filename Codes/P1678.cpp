// Problem: 
//     P1678 烦恼的高考志愿
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1678
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
	int m,n,ans=0,mincha,q,p,mid;
	cin>>m>>n;
	vector<int> a(m+5);//学校
	vector<int> b(n+5);//学生
	rep(i,m) cin>>a[i];
	rep(i,n) cin>>b[i];
	sort(a.begin(),a.begin()+m);//学校升序
	rep(i,n){	//遍历每一个学生
		q=0;
		p=m-1;
		mincha=10000000;
		while (q<=p)
		{
			mid=(q+p)/2;
			if (a[mid] == b[i]) {mincha=0;break;}
			else if (a[mid] > b[i]){
				mincha=min(mincha,a[mid]-b[i]);
				p=mid-1;
			}
			else {
				mincha=min(mincha,b[i]-a[mid]);
				q=mid+1;
			}
		}
		ans+=mincha;
	}
	cout<<ans;
	return 0;
}









