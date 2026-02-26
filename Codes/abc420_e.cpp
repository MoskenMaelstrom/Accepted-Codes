// Problem: E - Reachability Query
// Contest: AtCoder - AtCoder Beginner Contest 420
// URL: https://atcoder.jp/contests/abc420/tasks/abc420_e
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

struct DSU {
	vector<int> f,siz,cnt;
	
	DSU() {}
	DSU(int n) {
		init(n);
	}
	
	void init(int n) {
		f.resize(n);
		iota(f.begin(),f.end(),0);
		siz.assign(n,1);
		cnt.assign(n,0);
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
		cnt[x]+=cnt[y];
		f[y]=x;
		return 1;
	}
	
	void erase(int x) {
		x=find(x);
		cnt[x]--;
	}
	
	void add(int x) {
		x=find(x);
		cnt[x]++;
	}
	
	bool ok(int x) {
		x=find(x);
		if (cnt[x] == 0) return 0;
		else return 1;
	}
};

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<bool> a(n);
	
	DSU dsu(n);
	while (q--) {
		int o;
		cin>>o;
		if (o == 1) {
			int u,v;
			cin>>u>>v;
			u--,v--;
			dsu.merge(u,v);
		}
		else if (o == 2) {
			int v;
			cin>>v;
			v--;
			if (a[v]) dsu.erase(v);
			else dsu.add(v);
			a[v]=1-a[v];
		}
		else {
			int v;
			cin>>v;
			v--;
			if (dsu.ok(v)) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
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









