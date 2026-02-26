// Problem: 
//     P1918 保龄球
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1918
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
	int n,a;
	cin>>n;
	map<int,int> mp;
	int pos=1;
	rep(i,n) {
		cin>>a;
		mp[a]=pos++;
	}
	int m;
	cin>>m;
	rep(i,m) {
		cin>>a;
		if (!mp[a]) cout<<0<<endl;
		else cout<<mp[a]<<endl;
	}
	return 0;
}



