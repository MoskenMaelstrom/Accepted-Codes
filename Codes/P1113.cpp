// Problem: 
//     P1113 杂务
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1113
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

vector<int> g[10005];
vector<int> fg[10005];//记录反边
int rudu[10005]={0};
int t[10005];
int ans[10005]={0};//存每个点最大的耗时

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	
	int n;
	cin>>n;
	int num,c;
	for(int i=1;i<=n;i++) {
		cin>>num>>t[i];
		while (cin>>c and c) {g[c].push_back(i);rudu[i]++;fg[i].push_back(c);}
	}
	
	
	//求拓扑序
	vector<int> topo;
	vector<int> anst;
	
	while (anst.size() != n) {
		if (!topo.empty()) anst.insert(anst.end(),topo.begin(),topo.end());
		topo.clear();//清空topo
		for(int i=1;i<=n;i++){
			if (!rudu[i]) {
				topo.push_back(i);
				for(int j=0;j<g[i].size();j++) rudu[g[i][j]]--;
			}
		}
	}
	
	
	//对anst进行dp
	for(auto i:anst) {	//按拓扑序处理
		int ntime=0;
		for(int j=0;j<fg[i].size();j++) {
			ntime=max(ntime,ans[fg[i][j]]);
		}
		ans[i]=t[i]+ntime;
	}
	cout<<*max_element(ans+1,ans+n+1);
	
	
	return 0;
}







