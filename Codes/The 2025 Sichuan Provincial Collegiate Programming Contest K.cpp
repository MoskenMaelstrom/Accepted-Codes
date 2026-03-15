// Problem: K. Point Divide and Conquer
// Contest: Codeforces - The 2025 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105949/problem/K
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct DSU {
    vector<int> f,siz;
    int cnt;

    DSU():cnt(0) {}
    DSU(int n) {init(n);}

    void init(int n) {
        f.resize(n);
        iota(f.begin(),f.end(),0);
        siz.assign(n,1);
        cnt=n;
    }

    int find(int x) {
        while (x != f[x]) x=f[x]=f[f[x]];
        return x;
    }

    bool merge(int x,int y) {
        x=find(x);
        y=find(y);
        if (x == y) return 0;
        siz[x]+=siz[y];
        f[y]=x;
        cnt--;
        return 1;
    }

    int esize(int x) {
        return siz[find(x)];
    }
};

void solve()
{
	int n;
	cin>>n;
	vector<int> p(n+1);
	for(int i=1;i<=n;i++) cin>>p[i];
	vector adj(n+1,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	reverse(p.begin()+1,p.end());
	DSU dsu(n+1);
	vector<bool> vis(n+1);
	vector<int> pa(n+1);
	for(int i=1;i<=n;i++) {
		int u=p[i];
		vis[u]=1;
		for(auto v : adj[u]) {
			if (vis[v] and dsu.find(v) != u) {
				pa[dsu.find(v)]=u;
				dsu.merge(u,v);
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<pa[i]<<" ";
	cout<<"\n";
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







