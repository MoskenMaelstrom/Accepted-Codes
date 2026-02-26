// Problem: 
//     P3370 【模板】字符串哈希
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3370
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main()
{
	int n;
	string s;
	map<string,int> hash;
	cin>>n;
	int ans=n;
	while (n--){
		cin>>s;
		if (hash[s]) ans--;
		hash[s]=1;
	}
	cout<<ans;
	return 0;
}