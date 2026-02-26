// Problem: 
//     P4017 最大食物链计数
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4017
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int modn=80112002;

vector<int> g[5005];
vector<int> fg[5005];
int rudu[5005]={0};		//入度
int rudu1[5005]={0};	//还是入度
int chudu[5005]={0};	//出度
int ans[5005]={0};		//每个点对应的食物链数量

signed main()
{
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		cin>>a>>b;
		g[a].push_back(b);	
		fg[b].push_back(a);	//记录反边
		rudu[b]++;
		rudu1[b]++;
		chudu[a]++;
	}
	
	//拓扑排序存入anst
	vector<int> topo;
	vector<int> anst;
	while (anst.size() != n) 
	{
		if (!topo.empty()) anst.insert(anst.end(),topo.begin(),topo.end());
		topo.clear();
		for(int i=1;i<=n;i++) {
			if (rudu[i] == 0) {
				rudu[i]--;//已经排序的标记为-1
				topo.push_back(i);
				for(int j=0;j<g[i].size();j++) rudu[g[i][j]]--;
			}
		}
	}
	
	
	//按拓扑序遍历
	
	for(int i=1;i<=n;i++) {
		if (rudu1[i] == 0) ans[i]=1;
	}
	
	for(auto i:anst) 
	{
		int sum=0;
		for(int j=0;j<fg[i].size();j++) {
			sum+=ans[fg[i][j]];
			sum%=modn;
		}
		ans[i]+=sum;
		ans[i]%=modn;
	}
	
	//输出
	int sum=0;
	for(int i=1;i<=n;i++) {
		if (chudu[i] == 0) sum=(ans[i]+sum)%modn;
	}
	cout<<sum;
	
	return 0;
}








