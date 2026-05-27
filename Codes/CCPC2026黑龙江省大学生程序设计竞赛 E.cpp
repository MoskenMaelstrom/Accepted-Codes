// Problem: E. 乐乐的杏花
// Contest: Codeforces - CCPC2026黑龙江省大学生程序设计竞赛
// URL: https://codeforces.com/gym/106534/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
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

const int inf=1e18;
struct Info {
	int Min;
	Info() : Min(inf) {};
    Info(int val) : Min(val) {};
    Info operator+(const Info &other) const {
    	Info res;
    	res.Min=min(Min,other.Min);
    	return res;
    }
};

struct SegTree {
	int n;
	vector<Info> info;
    vector<int> ladd,lset;
    const int f=1e18+7; 

	SegTree(int _) {
		n=_;
		info.resize(n*4);
        ladd.resize(n*4,0);
        lset.resize(n*4,f);
	}
	
    void applyset(int v,int l,int r,int val) {
        // info[v].sum=(r-l+1)*val;
        info[v].Min=val;
        // info[v].Max=val;
        lset[v]=val;
        ladd[v]=0;
    }

    void applyadd(int v,int l,int r,int val) {
        // info[v].sum+=(r-l+1)*val;
        info[v].Min+=val;
        // info[v].Max+=val;
        if (lset[v] != f) {
            lset[v]+=val;
        } else {
            ladd[v]+=val;
        }
    }

    void pushdown(int v,int l,int r) {
        int m=l+r>>1;
        if (lset[v] != f) {
            applyset(v*2,l,m,lset[v]);
            applyset(v*2+1,m+1,r,lset[v]);
            lset[v]=f;
        }
        if (ladd[v] != 0) {
            applyadd(v*2,l,m,ladd[v]);
            applyadd(v*2+1,m+1,r,ladd[v]);
            ladd[v]=0;
        }
    }
	
    void Set(int v,int l,int r,int ql,int qr,int val) {
        if (ql > r or qr < l) return;
        if (ql <= l and r <= qr) {
            applyset(v,l,r,val);
            return;
        }
        pushdown(v,l,r);
        int m=l+r>>1;
        Set(v*2,l,m,ql,qr,val);
        Set(v*2+1,m+1,r,ql,qr,val);
        info[v]=info[v*2]+info[v*2+1];
    }

    void Add(int v,int l,int r,int ql,int qr,int val) {
        if (ql > r or qr < l) return;
        if (ql <= l and r <= qr) {
            applyadd(v,l,r,val);
            return;
        }
        pushdown(v,l,r);
        int m=l+r>>1;
        Add(v*2,l,m,ql,qr,val);
        Add(v*2+1,m+1,r,ql,qr,val);
        info[v]=info[v*2]+info[v*2+1];
    }

	Info query(int v,int l,int r,int ql,int qr) {
		if (ql > r or qr < l) return Info();
		if (ql <= l and r <= qr) return info[v];
        pushdown(v,l,r);
		int m=l+r>>1;
		return query(2*v,l,m,ql,qr)+query(2*v+1,m+1,r,ql,qr);
	}
};

void solve()
{
	int n,m;
	cin>>n>>m;
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	build(adj,0);
	int cur=0;
	vector<int> dfn(n);
	vector<int> siz(n,1);
	auto dfs=[&](auto&& self,int u,int fa) -> void {
		dfn[u]=cur++;
		for(auto v : adj[u]) {
			if (fa == v) continue;
			self(self,v,u);
			siz[u]+=siz[v];
		}
	};
	dfs(dfs,0,-1);
	
	SegTree st(n);
	for(int i=0;i<n<<2;i++) {
		st.info[i].Min=inf;
	}
	
	int x0=0;
	vector<bool> mark(n);
	while (m--) {
		int opt,x;
		cin>>opt>>x;
		x--;
		if (opt == 1) {
			if (!mark[dfn[x]]) st.Set(1,0,n-1,dfn[x],dfn[x],dist(x0,x)),mark[dfn[x]]=1;
			else st.Set(1,0,n-1,dfn[x],dfn[x],inf),mark[dfn[x]]=0;
		}
		else {
			if (deep[x] > deep[x0]) {
				st.Add(1,0,n-1,0,n-1,1);
				st.Add(1,0,n-1,dfn[x],dfn[x]+siz[x]-1,-2);
			}
			else {
				st.Add(1,0,n-1,0,n-1,-1);
				st.Add(1,0,n-1,dfn[x0],dfn[x0]+siz[x0]-1,2);
			}
			x0=x;
		}
		
		int ans=st.query(1,0,n-1,0,n-1).Min;
		if (ans > inf>>1) cout<<2147483648<<"\n";
		else cout<<ans<<"\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}







