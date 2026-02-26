// Problem: 
//     P1143 进制转换
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1143
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
char s[40],t[40];
signed main(){
	int b,m;
	cin>>b>>s>>m;
    to_chars(t,t+40,strtol(s,NULL,b),m);
    auto& f=use_facet<ctype<char>>(locale());
    f.toupper(t,t+40);
    cout<<t;
    return 0;
}