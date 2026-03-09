// Problem: H. Minimum Spanning Tree
// Contest: Codeforces - The 15th Shandong CCPC Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105930/problem/H
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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

int k,cnt;
DSU dsu;
vector<int> id;
int kruskal(int n,vector<array<int,4>>& E) {
	ranges::sort(E);
    int res=0;
    cnt=0;
    for (auto& [w,u,v,i] : E) {
    	if (dsu.find(u) != dsu.find(v)) {
            if (cnt >= n-1-k and w != 0 or cnt == n-1) break;
            dsu.merge(u,v);
        	id.push_back(i);
            res+=w;
            cnt++;
    	}
    }
	return res;
}

void solve()
{
	id.clear();
	int n,m;
	cin>>n>>m>>k;
	dsu.init(n);
	vector<array<int,4>> edge(m);
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		edge[i]={w,u,v,i+1};
	}
	
	int res=kruskal(n,edge);
	cnt=n-1-cnt;
	vector<array<int,2>> ans;
	for(int i=0;i<n-1;i++) {
		if (cnt == 0) break;
		if (dsu.merge(i,i+1)) {
			cnt--;
			res++;
			ans.push_back({i,i+1});
		}
	}
	
	cout<<ans.size()<<"\n";
	for(auto [u,v] : ans) cout<<u+1<<" "<<v+1<<"\n";
	cout<<res<<"\n";
	for(auto i : id) cout<<i<<" ";
	for(int i=m+1;i<m+1+ans.size();i++) cout<<i<<" ";
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







