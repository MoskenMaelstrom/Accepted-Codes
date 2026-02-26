// Problem: E - Distribute Bunnies
// Contest: AtCoder - Ｓｋｙ Inc, Programming Contest 2025 (AtCoder Beginner Contest 434)
// URL: https://atcoder.jp/contests/abc434/tasks/abc434_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
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
			x = f[x] = f[f[x]];
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

unordered_map<int,int> f;
int get(int n) {
	if (f.count(n)) return f[n];
	return f[n]=f.size();
}
void solve()
{
	int n;
	cin>>n;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++) {
		int x,r;
		cin>>x>>r;
		get(x-r);
		get(x+r);
		a[i]={f[x-r],f[x+r]};
	}
	
	DSU dsu(f.size());
	vector<bool> mark(f.size());//是不是环
	for(auto [l,r] : a) {
		if (dsu.same(l,r)) mark[dsu.find(l)]=1;
		if (mark[dsu.find(r)] == 1) mark[dsu.find(l)]=1;
		dsu.merge(l,r);
	}
	
	int ans=0;
	for(int i=0;i<f.size();i++) {
		if (i == dsu.find(i)) {
			if (mark[i]) ans+=dsu.elesize(i);
			else ans+=dsu.elesize(i)-1;
		}
	}
	cout<<ans;
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







