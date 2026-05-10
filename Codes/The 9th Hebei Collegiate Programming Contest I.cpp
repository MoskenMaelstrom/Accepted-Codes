// Problem: I. 感染
// Contest: Codeforces - The 9th Hebei Collegiate Programming Contest
// URL: https://codeforces.com/gym/105909/problem/I
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

vector<int> Centroid(vector<vector<int>>& adj) {
    int n=adj.size();
    vector<int> res;
    vector<int> siz(n,0);
    int maxn=n+1;

    auto dfs=[&](auto&& self,int u,int fa) -> void {
        siz[u]=1;
        int x=0; 

        for (int v : adj[u]) {
        	if (v == fa) continue;
            self(self,v,u);
            siz[u]+=siz[v];
            x=max(x,siz[v]);
        }
        x=max(x,n-siz[u]);

        if (x < maxn) {
            maxn=x;
            res.clear();
            res.push_back(u);
        } 
        else if (x == maxn) {
            res.push_back(u);
        }
    };
    
    dfs(dfs,0,-1);
    return res;
}

void solve()
{
	int n;
	cin>>n;
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	auto res=Centroid(adj);
	cout<<res.size()<<endl;
	ranges::sort(res);
	for(auto u : res) cout<<u+1<<" ";
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







