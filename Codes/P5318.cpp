// Problem: 
//     P5318 【深基18.例3】查找文献
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5318
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
bool flag[MAXN]={0};
vector<int> g[MAXN];

void dfs(int x)
{
	cout<<x<<" ";
	for(int i=0;i<g[x].size();i++) {
		if (flag[g[x][i]]) continue;
		flag[g[x][i]]=1;
		dfs(g[x][i]);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++) {
		cin>>a>>b;
		g[a].push_back(b);
	}
	for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	
	
	flag[1]=1;//从第一个开始
	dfs(1);
	cout<<"\n";
	
	
	memset(flag,0,sizeof(flag));
	queue<int> q;
	q.push(1);
	flag[1]=1;
	int pos;
	while (!q.empty()){
		pos=q.front();
		q.pop();	
		cout<<pos<<" ";
		for(int i=0;i<g[pos].size();i++) {
			if (flag[g[pos][i]]) continue;
			q.push(g[pos][i]);
			flag[g[pos][i]]=1;
		}
	}
	return 0;
}









