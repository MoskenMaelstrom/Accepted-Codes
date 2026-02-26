// Problem: 
//     P3879 [TJOI2010] 阅读理解
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3879
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
signed main()
{
	set<string> st[1005];
	int n;
	string w;
	cin>>n;
	rep(i,n){
		int t;
		cin>>t;
		rep(j,t) {
			cin>>w;
			if(st[i].find(w) == st[i].end()) st[i].insert(w);
		}
	}
	
	int m;
	cin>>m;
	int pw;
	rep(k,m) {
		cin>>w;	
		pw=0;
		rep(i,n) {
			if (st[i].find(w) != st[i].end()) {
				if (pw) cout<<pw<<" ";
				pw=i;
			}
		}
		if (pw) cout<<pw<<endl;
		else cout<<"\n";
	}
	
	return 0;
}






