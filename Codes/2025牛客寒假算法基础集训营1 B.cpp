// Problem: 一气贯通之刃
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95323/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct DSU {
	vector<int> f,siz;A
	
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

void solve()
{
	int n;
	cin>>n;
	vector<int> a1(n,0);
	DSU a(n);
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		a1[u]++;
		a1[v]++;
		a.merge(u,v);
	}
	
	int flag=1; 
	for(int i=0;i<n;i++) if (a1[i] >= 3) flag=0;
	if (a.count() == 1 and flag) {
		for(int i=0;i<n;i++) if (a1[i] == 1) cout<<i+1<<" ";
	} else {
		cout<<"-1";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	solve();
	return 0;
}









