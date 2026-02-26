// Problem: 
//     P1106 删数问题
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1106
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int find_min(string s,int len)
{
	int mina=1000;
	int mini=0;//10234
		rep(i,len+1)
			if (s[i]<mina) {
				mina=s[i];
				mini=i;
			}
	return mini;
}
signed main()
{
	string s,ans="";
	int k,pos,sum=0;
	cin>>s>>k;
	if (s=="0"){
		cout<<0;
		return 0;
	}
	int len=s.length();
	int rest=len-k;
	while (sum!=rest)
	{
		pos=find_min(s,k);
		ans+=s[pos];
		s.erase(0,pos+1);
		k-=pos;
		sum++;
	}
	rep(i,ans.length())
	{
		pos=i;
		if (ans[i]!='0')break;
	}
	ans.erase(0,pos);
	cout<<ans;
	return 0;
}