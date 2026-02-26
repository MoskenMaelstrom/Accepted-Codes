// Problem: 
//     P2392 kkksc03考前临时抱佛脚
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2392
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n[4],s[30];
int maxdeep,wholetime,maxtime,nowtime,ans=0;
void dfs(int x)		//深搜maxtime
{
	if (x == maxdeep) {
		maxtime=max(maxtime,nowtime);
		return;
	}
	if (nowtime+s[x] > wholetime/2)	{dfs(x+1);return;}	//超了总时长的一半
	if (nowtime+s[x] == wholetime/2) {					//刚好是一半
		maxtime=wholetime/2;
		return;
	}
	nowtime+=s[x];										//不足一半
	dfs(x+1);
	nowtime-=s[x];
	dfs(x+1);
	return;
}
signed main()
{
	rep(i,4) cin>>n[i];
	
	rep(k,4)
	{
		wholetime=0;
		maxtime=0;
		nowtime=0;
		maxdeep=n[k];
		rep(i,maxdeep){ 
			cin>>s[i]; 			//s里面存的一科里所有题目
			wholetime+=s[i];	//计算总时间
		}
		dfs(0);					//深搜maxtime
		ans+=wholetime-maxtime;
	}

	
	cout<<ans;
	return 0;
}











