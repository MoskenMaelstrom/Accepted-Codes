// Problem: 
//     P3367 【模板】并查集
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3367
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
struct DSU {
	vector<int> f,siz;
	
	DSU() {}
	DSU(int n) {
		init(n);
	}
	
	void init(int n) {
		f.resize(n);
		iota(f.begin(),f.end(),0);
		siz.assign(n,1);
	}
	
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];//路径压缩，使树扁平
		}
		return x;
	}
	
	bool same(int x,int y) {
		return find(x) == find(y);
	}
	
	bool merge(int x,int y) {
		x=find(x);
		y=find(y);
		if (x == y) return 0;
		siz[x] += siz[y];
		f[y]=x;
		return 1;
	}
	
	int elesize(int x) {
		return siz[find(x)];
	}
	
	//返回根的数量
	int count() {
		unordered_set<int> roots;
		for(int i=0;i<f.size();i++) roots.insert(find(i));
		return roots.size();
	}
};

signed main()
{
	int n,m;
	cin>>n>>m;
	DSU a(n);
	for(int i=0;i<m;i++) {
		int z,x,y;
		cin>>z>>x>>y;
		x--;
		y--;
		if (z == 1) a.merge(x,y);
		else {
			a.same(x,y) ? cout<<"Y\n" : cout<<"N\n";
		}
	}
	return 0;
}














