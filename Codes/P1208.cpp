// Problem: 
//     P1208 [USACO1.3] 混合牛奶 Mixing Milk
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1208
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
struct milk{
	int p,a;
};
bool cmp(milk a1,milk a2)
{
	return a1.p<a2.p;
}
signed main()
{
	int n,m,ans=0;
	cin>>n>>m;
	vector<milk> arr(m+5);
	rep(i,m) cin>>arr[i].p>>arr[i].a;
	sort(arr.begin(),arr.begin()+m,cmp);
	rep(i,m){
		if(n>=arr[i].a){
			n-=arr[i].a;
			ans+=arr[i].a*arr[i].p;
			if(n==0)break;
		}
		else {
			ans+=arr[i].p*n;
			break;
		}
	}
	cout<<ans;
	return 0;
}





