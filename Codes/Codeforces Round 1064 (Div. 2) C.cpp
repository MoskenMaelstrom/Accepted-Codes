// Problem: C. Cyclic Merging
// Contest: Codeforces - Codeforces Round 1064 (Div. 2)
// URL: https://codeforces.com/contest/2166/problem/C
// Memory Limit: 256 MB
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

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<array<int,2>> b(n);
	DSU dsu(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		b[i][0]=a[i];
		b[i][1]=i;
	}
	ranges::sort(b);
	
	int ans=0;
	for(int i=0;i<n;i++) {
		int id=b[i][1];
		int i0=(id-1+n)%n;
		int i1=(id+1+n)%n;
		if (a[id] >= a[i0] and !dsu.same(id,i0)) {
			dsu.merge(id,i0);
			ans+=a[id];
		}
		if (a[id] >= a[i1] and !dsu.same(id,i1)) {
			dsu.merge(id,i1);
			ans+=a[id];
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







