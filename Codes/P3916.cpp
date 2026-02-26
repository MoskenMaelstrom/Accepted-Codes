// Problem: 
//     P3916 图的遍历
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3916
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
vector<int> g[MAXN];
int ans[MAXN]={0};

void dfs(int x,int y)
{
	ans[x]=y;
	for(int i=0;i<g[x].size();i++) 
		if (ans[g[x][i]] == 0) dfs(g[x][i],y);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		cin>>a>>b;
		g[b].push_back(a);	//建立反向边
	}
	
	for(int i=n;i>0;i--) {
		if (ans[i] == 0) {
			dfs(i,i);
		}
	}
	
	
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}













