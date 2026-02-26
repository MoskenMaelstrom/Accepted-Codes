// Problem: 
//     P1090 [NOIP2004 提高组] 合并果子 / [USACO06NOV] Fence Repair G
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1090
// Memory Limit: 125 MB
// Time Limit: 800 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int n,w,ans=0;
	cin>>n;
	priority_queue<int,vector<int>,greater<int> > a;
	rep(i,n){
		cin>>w;
		a.push(w);	
	}
	rep(i,n-1){
		w=a.top();
		a.pop();
		w+=a.top();
		a.pop();
		a.push(w);
		ans+=w;
	}
	cout<<ans;
	return 0;
}