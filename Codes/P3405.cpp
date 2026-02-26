// Problem: 
//     P3405 [USACO16DEC] Cities and States S
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3405
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
map<int,int> mp[3000];
signed main()
{
	int n,ans=0;
	string s1,s2;
	cin>>n;
	rep(i,n){
		cin>>s1>>s2;
		int pos1=s1[1]*26+s1[0];
		int pos2=s2[1]*26+s2[0];
		ans+=mp[pos2][pos1];
		if (pos1 == pos2) ans-=mp[pos2][pos1];
		mp[pos1][pos2]++;
	}
	cout<<ans;
	return 0;
}