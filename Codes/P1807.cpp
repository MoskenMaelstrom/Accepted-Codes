// Problem: 
//     P1807 最长路
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1807
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
vector<int> g[50005];	//邻接表
int numru[50005];	//入度的量
vector<int> chu[50005];	//出度
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	//存图与出度
	int u,v,w;
	for(int i=1;i<=m;i++) {
		cin>>u>>v>>w;
		g[u].push_back(v);
		chu[u].push_back(w);
		numru[v]++;
	}
	//求topo
	vector<int> topo;//拓扑序
	vector<int> temp;//暂存
	while (temp.size() != n) {
		if (!temp.empty()) topo.insert(topo.end(),temp.begin(),temp.end());
		temp.clear();
		for(int i=1;i<=n;i++) {
			if (numru[i] == 0) {
				numru[i]--;
				temp.push_back(i);
				for(int j=0;j<g[i].size();j++) numru[g[i][j]]--;
			}
		}
	}
	//按拓扑序遍历图
	for(auto i:topo)
	{
		
	}
	//输出
	cout<<ans;
	
	return 0;
}









