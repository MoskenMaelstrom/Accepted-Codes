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
	int n,q;
	cin>>n>>q;
	DSU dsu[4096];
	for(int i=0;i<4096;i++) dsu[i].init(n);
	function<void(int,int,int)> Add=[&](int u,int v,int mask) {
		if (dsu[mask].same(u,v)) return;
		else {
			dsu[mask].merge(u,v);
			for(int b=11;b>=0;b--) {
				if (((mask>>b)&1)) Add(u,v,mask^(1<<b));
			}
		}
	};
	
	int ans=0;
	for(int i=0;i<q;i++) {
		char op;
		cin>>op;
		if (op == '+') {
			int u,v,w;
			cin>>u>>v>>w;
			u--,v--;
			Add(u,v,w);
		}
		else {
			int u,v;
			cin>>u>>v;
			u--,v--;
			if (!dsu[0].same(u,v)) ans--;
			else {
				int cur=0;
				for(int b=11;b>=0;b--) {
					int mask=cur|(1<<b);
					if (dsu[mask].same(u,v)) cur=mask;
				}
				ans+=cur;
			}
		}
	}
	cout<<ans<<'\n';
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







