// Problem: C. Fools and Roads
// Contest: Codeforces - Codeforces Round 121 (Div. 1)
// URL: https://codeforces.com/problemset/problem/191/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

vector<vector<int>> fa;
vector<int> deep;
vector<int> ord;
void build(vector<vector<int>> &adj,int r) {
	int n=adj.size();
    int m=__lg(n)+1;
    fa.assign(m+1,vector<int>(n,-1));
    deep.assign(n,-1);
    
    queue<int> q;
    q.push(r);
    deep[r]=0;
    fa[0][r]=-1;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        ord.push_back(u);
        
        for (int v : adj[u]) {
            if (deep[v] == -1) {
                deep[v]=deep[u]+1;
                fa[0][v]=u;
                q.push(v);
            }
        }
    }
    
    for (int k=1;k<=m;k++) {
        for (int u=0;u<n;u++) {
            if (fa[k-1][u] != -1) {
                fa[k][u]=fa[k-1][fa[k-1][u]];
            } else {
                fa[k][u]=-1;
            }
        }
    }
}

int lift(int u,int target) {
    int dif=deep[u]-target;
    int k=0;
    while (dif > 0) {
        if (dif&1) u=fa[k][u];
        dif>>=1;
        k++;
    }
    return u;
}

int query(int u,int v) {
    if (deep[u] < deep[v]) swap(u,v);
    u=lift(u,deep[v]);
    if (u == v) return u;
    
    int m=fa.size()-1;
    for (int k=m;k>=0;k--) {
        if (fa[k][u] != fa[k][v]) {
            u=fa[k][u];
            v=fa[k][v];
        }
    }

    return fa[0][u];
}

int dist(int u,int v) {
    return deep[u]+deep[v]-2*deep[query(u,v)];
}

void solve()
{
	int n;
	cin>>n;
	vector adj(n,vector<int>(0));
	map<array<int,2>,int> mp;
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		mp[{u,v}]=i;
		mp[{v,u}]=i;
	}
	
	build(adj,0);
	vector<int> vec(n);
	int q;
	cin>>q;
	while (q--) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		vec[u]++;
		vec[v]++;
		vec[query(u,v)]-=2;
	}
	
	ranges::reverse(ord);
	vector<int> ans(n-1);
	for(int i=0;i<n;i++) {
		int u=ord[i];
		if (u == 0) continue;
		vec[fa[0][u]]+=vec[u];
		ans[mp[{u,fa[0][u]}]]=vec[u];
	}
	for(auto e1 : ans) cout<<e1<<" ";
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







