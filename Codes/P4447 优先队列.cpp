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
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
priority_queue<int,vector<int>,greater<int> > b[1000005];//每个小顶堆存顶部实力为下标的各个小组的amount
signed main()
{
	int n,k=0;
	cin>>n;
	map<int,int> mp;						//映射一个mp维护b
	vector<int> a(n+5);
	rep(i,n)cin>>a[i];
	sort(a.begin(),a.begin()+n);			//升序
	
	
	rep(i,n)								//遍历每一个a[i]
	{
		if (!mp.count(a[i])) mp[a[i]]=k++;
		if (!mp.count(a[i]-1)) mp[a[i]-1]=k++;
		
		if (b[mp[a[i]-1]].size()) {			//a[i]-1堆不空
			b[mp[a[i]]].push(b[mp[a[i]-1]].top()+1);
			b[mp[a[i]-1]].pop();
		}
		else								//a[i]-1堆空
			b[mp[a[i]]].push(1);
	}
	
	
	int ans=100005;
	rep(i,k){
		if (b[i].size()) ans=min(ans,b[i].top());
	}
	cout<<ans;
	
	return 0;
}








