// Problem: Fish Eating
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/133876/C
// Memory Limit: 2048 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

vector<int> vec;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
struct DSU {
    vector<int> f,siz;
    vector<int> val;
    int cnt;

    DSU(int n) {init(n);}

    void init(int n) {
        f.resize(n);
        iota(f.begin(),f.end(),0);
        siz.assign(n,1);
        val.assign(n,0);
        cnt=n;
    }

    int find(int x) {
    	if (x == f[x]) return x;
    	int r=find(f[x]);
    	val[x]=max(val[x],val[f[x]]);
        return f[x]=r;
    }

    bool merge(int x,int y) {
        int fx=find(x);
        int fy=find(y);
        if (fx == fy) return 0;
        val[fy]=vec[fx]-(siz[fy]-1);
        siz[fx]+=siz[fy];
        f[fy]=fx;
        cnt--;
        return 1;
    }
};

void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	vec.assign(n*m,0);
	DSU dsu(n*m);
	int l=0;
	while (q--) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int x,y,v;
			cin>>x>>y>>v;
			x^=l;
			y^=l;
			int id=(x-1)*m+y-1;
			vec[id]=v;
			set<int> st;
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				int id1=(nx-1)*m+ny-1;
				if (nx <= 0 or nx > n or ny <= 0 or ny > m or vec[id1] == 0) continue;
				st.insert(dsu.find(id1));
			}
			for(auto id1 : st) dsu.merge(id,id1);
			l=dsu.siz[id]-1;
			cout<<l<<"\n";
		}
		else {
			int x,y;
			cin>>x>>y;
			x^=l;
			y^=l;
			int id=(x-1)*m+y-1;
			dsu.find(id);
			l=max(dsu.val[id],vec[id])-vec[id];
			cout<<l<<"\n";
		}
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







