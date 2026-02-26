// Problem: 
//     P8200 [传智杯 #4 决赛] 生活在树上（easy version）
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8200
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int N=5e5+5;
struct tree {
	int p,n;//这个点 以及 到这个点的边权
};

vector<tree> g[N];//邻接表
vector<int> b(N,0);//存的是这个点一直异或到点"1"的值
vector<bool> mark(N,0);//标记用

void dfs(int x)
{
	//遍历这个点的 可到达的点
	for(auto [p,n] : g[x]) {
		if (mark[p]) continue;
		mark[p]=1;//标记
		b[p]=(b[x]^n);
		dfs(p);
	}
}
signed main()	
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	n--;
	for(int i=1;i<=n;i++) {
		int x,y,l;
		cin>>x>>y>>l;//10 110
		g[x].push_back({y,l});
		g[y].push_back({x,l});
	}
	mark[1]=1;//标记1点
	dfs(1);//从1开始遍历
	
	//查询
	for(int i=1;i<=m;i++) {
		int a1,a2,k;
		cin>>a1>>a2>>k;
		bool flag=1;
		if ((b[a1]^b[a2]) == k) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}







