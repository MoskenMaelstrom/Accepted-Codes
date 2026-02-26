// Problem: 
//     P1019 [NOIP2000 提高组] 单词接龙
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1019
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,mark[25]={0},ans=0;
string ss[25];

string pj(string s1,string s2)
{
	int len1=s1.length();
	int len2=s2.length();
	for(int i=1;i<len1 and i<len2;i++)
		if (s1.substr(len1-i,i) == s2.substr(0,i))
			return s1+s2.substr(i,len2-i);
	return "0";
}

void dfs(string dra)
{
	if (dra.length() > ans) ans=dra.length();
	rep(i,n){		//遍历所有单词
		if (mark[i] == 2) continue;
		string s=pj(dra,ss[i]);
		if (s != "0") {
			mark[i]++;
			dfs(s);
			mark[i]--;
		}
	}
}

signed main()
{
	char c;
	cin>>n;
	rep(i,n) cin>>ss[i];
	cin>>c;
	
	rep(i,n) {
		if (ss[i][0] == c){
			mark[i]++;
			dfs(ss[i]);
			mark[i]--;
		}
	}
	cout<<ans;
	return 0;
}













