// Problem: P3366 【模板】最小生成树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3366
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
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
	DSU dsu(n);
	vector<array<int,3>> a;
	for(int i=0;i<m;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		x--;
		y--;
		a.push_back({z,x,y});
	}
	
	int ans=0;
	ranges::sort(a);
	for(int i=0;i<m;i++) {
		auto [z,x,y]=a[i];
		if (dsu.same(x,y)) continue;
		dsu.merge(x,y);
		ans+=z;
	}
	
	for(int i=0;i<n;i++) {
		if (dsu.elesize(i) == n) {cout<<ans;return;}
	}
	cout<<"orz";
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









