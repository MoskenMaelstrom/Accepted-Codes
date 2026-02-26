#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> siz;
vector<int> Centroid(const vector<vector<int>>& adj,int st,int m) {
    int n=adj.size();
    vector<int> res;
    siz.assign(n,0);
    int maxn=n+1;

    function<void(int, int)> dfs = [&](int u, int fa) {
        siz[u]=1;
        int x=0; 

        for (int v : adj[u]) {
        	if (v == fa) continue;
            dfs(v,u);
            siz[u]+=siz[v];
            x=max(x,siz[v]);
        }

        x=max(x,m-siz[u]);

        if (x < maxn) {
            maxn=x;
            res.clear();
            res.push_back(u);
        } 
        else if (x == maxn) {
            res.push_back(u);
        }
    };
    
    dfs(st,-1);
    return res;
}

int query(int u,int v) {
	u++,v++;
	cout<<"? "<<u<<" "<<v<<endl;
	int res;
	cin>>res;
	return res;
}

void solve()
{
	int n;
	cin>>n;
	vector adj(n,vector<int>(0));
	for(int i=0;i<n;i++) {
		int u,v;
		cin>>u>>v;
		if (u != 0) {
			u--;
			adj[i].push_back(u);
			adj[u].push_back(i);
		}
		if (v != 0) {
			v--;
			adj[i].push_back(v);
			adj[v].push_back(i);
		}
	}
	
	int m=n;
	auto vec=Centroid(adj,0,m);
	while (1) {
		int zx=vec[0];
		if (adj[zx].size() == 0) {cout<<"! "<<zx+1<<endl;break;}
		else if (adj[zx].size() == 1) {
			int p1=adj[zx][0];
			int res=query(zx,p1);
			if (res == 0) {cout<<"! "<<zx+1<<endl;break;}
			if (res == 2) {cout<<"! "<<p1+1<<endl;break;}
		}
		else if (adj[zx].size() == 2) {
			Centroid(adj,zx,m);
			int p1=adj[zx][0];
			int p2=adj[zx][1];
			int res=query(p1,p2);
			if (res == 0) {
				adj[p1].erase(ranges::find(adj[p1],zx));
				m=siz[p1];
				vec=Centroid(adj,p1,m);
			}
			if (res == 1) {
				cout<<"! "<<zx+1<<endl;
				break;
			}
			if (res == 2) {
				adj[p2].erase(ranges::find(adj[p2],zx));
				m=siz[p2];
				vec=Centroid(adj,p2,m);
			}
		}
		else {
			Centroid(adj,zx,m);
			int p1=adj[zx][0];
			int p2=adj[zx][1];
			int p3=adj[zx][2];
			if (siz[p1] < siz[p2]) swap(p1,p2);
			if (siz[p1] < siz[p3]) swap(p1,p3);
			if (siz[p2] < siz[p3]) swap(p2,p3);
			int res=query(p1,p2);
			if (res == 0) {
				adj[p1].erase(ranges::find(adj[p1],zx));
				m=siz[p1];
				vec=Centroid(adj,p1,m);
			}
			if (res == 1) {
				adj[zx].clear();
				adj[zx].push_back(p3);
				m=siz[p3]+1;
				vec=Centroid(adj,zx,m);
			}
			if (res == 2) {
				adj[p2].erase(ranges::find(adj[p2],zx));
				m=siz[p2];
				vec=Centroid(adj,p2,m);
			}
		}
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







