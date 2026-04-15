#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

vector<vector<int>> fa;
vector<int> deep;
const int M=30;
void build(vector<vector<int>> &adj,int r) {
	int n=adj.size();
    fa.assign(M+1,vector<int>(n,-1));
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
    
    for (int k=1;k<=M;k++) {
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
	int n,q;
	cin>>n>>q;
	vector adj(n,vector<int>(0));
	vector<int> c(n);
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	build(adj,0);
	
	vector vec(n,vector<int>(0));
	for(int i=1;i<n;i++) {
		vec[fa[0][i]].push_back(i);
	}
	
	auto dp=c;
	auto dfs=[&](auto&& self,int u) -> void {
		if (vec[u].empty()) return;
		for(auto v : vec[u]) {
			self(self,v);
		}
		ranges::sort(vec[u],[&](int X,int Y) {
			return dp[X] < dp[Y];
		});
		dp[u]=min(dp[u],dp[vec[u][0]]+dp[vec[u][1]]);
	};
	dfs(dfs,0);
	
	vector st(30,vector<int>(n));
	for(int i=1;i<n;i++) {
		int pa=fa[0][i];
		st[0][i]=vec[pa][0] == i ? dp[vec[pa][1]] : dp[vec[pa][0]];
	}
	for(int j=1;j<30;j++) {
		for(int i=1;i<n;i++) {
			if (fa[j][i] == -1) continue;
			st[j][i]=st[j-1][i]+st[j-1][fa[j-1][i]];
		}
	}
	
	while (q--) {
		int x,y;
		cin>>x>>y;
		x--,y--;
		if (query(x,y) != y) {cout<<"-1\n";continue;}
		int dis=dist(x,y),k=0;
		int ans=0;
		while (dis) {
			if (dis&1) {
				ans+=st[k][x];
				x=fa[k][x];
			}
			dis>>=1;
			k++;
		}
		cout<<ans<<"\n";
	}
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







