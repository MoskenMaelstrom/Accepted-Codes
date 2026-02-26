// Problem: D. Connect the Dots
// Contest: Codeforces - Codeforces Round 976 (Div. 2) and Divide By Zero 9.0
// URL: https://codeforces.com/problemset/problem/2020/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(m),d(m),k(m);
	for(int i=0;i<m;i++) {
		cin>>a[i]>>d[i]>>k[i];
		a[i]--;
	}
	DSU dsu(n);
	
	for(int x=1;x<=10;x++) {
		vector<int> f(n,0);
		for(int i=0;i<m;i++) {
			if (x == d[i]) f[a[i]]++,f[a[i]+k[i]*d[i]]--;
		}
		for(int i=x;i<n;i++) f[i]+=f[i-x];
		for(int i=0;i<n;i++) if (f[i] > 0) dsu.merge(i,i+x); 
	}
	
	cout<<dsu.count()<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









