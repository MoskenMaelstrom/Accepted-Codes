// Problem: P1640 [SCOI2010] 连续攻击游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1640
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

struct DSU {
	vector<int> f,siz;
	
	DSU() {}
	DSU(int n) {init(n);}
	
	void init(int n) {
		f.resize(n);
		iota(f.begin(),f.end(),0);
		siz.assign(n,1);
	}
	
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}
	
	bool merge(int x,int y) {
		x=find(x);
		y=find(y);
		if (x == y) return 0;
		if (x > y) {
			siz[x] += siz[y];
			f[y]=x;	
		}
		else {
			siz[y] += siz[x];
			f[x]=y;
		}
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

const int N=1e4;
void solve()
{
	int n;
	cin>>n;
	DSU dsu(N+1);
	vector<bool> mark(N+1);
	for(int i=0;i<n;i++) {
		int u,v;
		cin>>u>>v;
		if (dsu.find(u) == dsu.find(v)) mark[dsu.find(u)]=1;
		if (mark[dsu.find(v)]) mark[dsu.find(u)]=1;
		if (mark[dsu.find(u)]) mark[dsu.find(v)]=1;
		dsu.merge(u,v);
	}
	
	vector<int> ans(N+1);
	for(int i=1;i<=N;i++) {
		if (mark[dsu.find(i)] or i != dsu.find(i)) ans[i]=1;
	}
	for(int i=1;i<=N;i++) {
		if (!ans[i]) {
			cout<<i-1;
			return;
		}
	}
	cout<<N;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







