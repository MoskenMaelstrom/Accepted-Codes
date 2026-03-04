// Problem: J. Colorful Spanning Tree
// Contest: Codeforces - The 2024 CCPC Shandong Invitational Contest and Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105385/problem/J
// Memory Limit: 1024 MB
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
	
	int count() {
		unordered_set<int> roots;
		for(int i=0;i<f.size();i++) roots.insert(find(i));
		return roots.size();
	}
};

int kruskal(int n,vector<array<int,3>>& E) {
	ranges::sort(E);
    DSU dsu(n);
    int res=0,cnt=0;
    for (auto& [w,u,v] : E) {
        if (dsu.merge(u,v)) {
            res+=w;
            cnt++;
            if (cnt == n-1) break;
        }
    }
    assert(cnt == n-1);
	return res;
}

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector adj(n,vector<int>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>adj[i][j];
		}
	}
	
	vector<array<int,3>> edge;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			edge.push_back({adj[i][j],i,j});
		}
	}
	int ans=kruskal(n,edge);
	for(int i=0;i<n;i++) {
		ans+=(a[i]-1)*(*ranges::min_element(adj[i]));
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







