// Problem: E. Boomerang
// Contest: Codeforces - 2024 ICPC National Invitational Collegiate Programming Contest, Wuhan Site
// URL: https://codeforces.com/gym/105143/problem/E
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

vector<vector<int>> fa;
vector<int> deep;
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
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int r,t0;
	cin>>r>>t0;
	r--;
	vector<int> dia(n);
	build(adj,r);
	vector tdis(n,vector<int>(0));
	for(int i=0;i<n;i++) {
		tdis[deep[i]].push_back(i);
	}
	int A=r,B=r,maxn=0;
	for(int t=0;t<n;t++) {
		for(int u : tdis[t]) {
			int d1=dist(A,u);
			int d2=dist(B,u);
			if (d1 > maxn and d1 >= d2) B=u,maxn=d1;
			if (d2 > maxn and d2 >= d1) A=u,maxn=d2;
		}
		dia[t]=maxn;
	}
	
	vector<int> ans(n+1);
	int t=t0;
	for(int k=n;k>=1;k--) {
		while ((t-t0)*k*2 < dia[min(t,n-1)]) t++;
		ans[k]=t;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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







