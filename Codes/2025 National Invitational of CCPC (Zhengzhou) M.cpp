// Problem: M. 川陀航空学院
// Contest: Codeforces - 2025 National Invitational of CCPC (Zhengzhou), 2025 CCPC Henan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105941/problem/M
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
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
		siz[x] += siz[y];
		f[y]=x;
		return 1;
	}
	
	int esize(int x) {
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
	int cnt=0;
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		if (dsu.merge(u,v) == 0) cnt++;
	}
	
	for(int i=1;i<n;i++) {
		if (dsu.find(i) != dsu.find(i-1)) {
			cnt++;
			dsu.merge(i,i-1);
		}
	}
	cout<<cnt;
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







