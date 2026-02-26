// Problem: P2886 [USACO07NOV] Cow Relays G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2886
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

//Min-Plus求floyd最短路
const int inf=1e18;
vector<vector<int>> operator * (const vector<vector<int>>& A,const vector<vector<int>>& B) {
	const int n=A.size();
	vector C(n,vector<int>(n,inf));
    for (int i=0;i<n;i++) {
        for (int k=0;k<n;k++) {
        	if (A[i][k] == inf) continue;
            for (int j=0;j<n;j++) {
                C[i][j]=min(C[i][j],A[i][k]+B[k][j]);
            }
        }
    }
    return C;
}

vector<vector<int>> Pow(vector<vector<int>> A,int exp) {
	int n=A.size();
	vector res(n,vector<int>(n,inf));
	for(int i=0;i<n;i++) res[i][i]=0;
	while (exp) {
		if (exp&1) res=res*A;
		A=A*A;
		exp>>=1;
	}
	return res;
}

void solve()
{
	map<int,int> mp;
	function<int(int)> get=[&](int x) {
		if (mp.count(x) == 0) {
			mp[x]=mp.size();
		}
		return mp[x];
	};
	
	int N,m,S,E;
	cin>>N>>m>>S>>E;
	get(S);
	get(E);
	
	vector<array<int,3>> edge(m);
	for(int i=0;i<m;i++) {
		int w,u,v;
		cin>>w>>u>>v;
		edge[i]={w,u,v};
		get(u);
		get(v);
	}
	
	int n=mp.size();
	vector adj(n,vector<int>(n,inf));
	for(auto& [w,u,v] : edge) {
		u=get(u);
		v=get(v);
		adj[u][v]=min(adj[u][v],w);
		adj[v][u]=min(adj[v][u],w);
	}
	
	auto ans=Pow(adj,N);
	cout<<ans[get(S)][get(E)];
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







