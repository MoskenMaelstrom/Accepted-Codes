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
	int n,m1,m2;
	cin>>n>>m1>>m2;
	vector<array<int,2>> a(m1);
	DSU d2(n);
	for(int i=0;i<m1;i++) {
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		a[i]={u,v};
	}
	for(int i=0;i<m2;i++) {
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		d2.merge(u,v);
	}
	
	DSU d3(n);//记录g和f都联通的点
	int cnt=0;
	for(auto [u,v] : a) {
		if (!d2.same(u,v)) cnt++;//发现f里面联通的g里面没联通，就把f里面的删掉，操作数++
		else d3.merge(u,v);
	}
	cout<<cnt+(n-d2.count())-(n-d3.count())<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}









