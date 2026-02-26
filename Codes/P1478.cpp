// Problem: 
//     P1478 陶陶摘苹果（升级版）
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1478
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
struct apple{
	int h,st;
};
bool cmp(apple a1,apple a2)
{
	return a1.st<a2.st;
}
signed main()
{
	int n,s,a,b,hi;
	cin>>n>>s>>a>>b;
	hi=a+b;
	vector<apple> arr(n+5);
	rep(i,n)cin>>arr[i].h>>arr[i].st;
	sort(arr.begin(),arr.begin()+n,cmp);
	int pos=0,sum=0;
	while (s>0)
	{
		if(arr[pos].h>hi){
			pos++;
			continue;
		}
		else{
			if(arr[pos].st<=s){
				s-=arr[pos].st;
				pos++;
				sum++;
			}
			else break;
		}
	}
	cout<<sum;
	return 0;
}







