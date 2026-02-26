// Problem: 
//     P2814 家谱
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2814
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
//需要一个hash存 名称:父亲的名称
unordered_map<string,string> h;
string fin(string x)
{
	if (x != h[x]) h[x]=fin(h[x]);
	return h[x];
}
string father;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	string s;
	while (1) {
		cin>>s;
		if (s == "$") break;
		if (s[0] == '#') 
		{
			s.erase(0,1);
			father=s;
			if (h.find(s) == h.end()) h[s]=s;//如果未出现过，就指向自己
		}
		else if (s[0] == '+')
		{
			s.erase(0,1);
			h[s]=fin(father);	//指向父亲节点
		}
		else
		{
			s.erase(0,1);
			cout<<s<<" "<<fin(h[s])<<endl;	
		}
	}
//	for(auto it=h.begin();it!=h.end();it++) {
//		cout<<it->first<<" : "<<it->second<<endl; 
//	}
	return 0;
}





