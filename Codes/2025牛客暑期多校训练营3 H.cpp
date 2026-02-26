// Problem: Head out to the Target
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108300/H
// Memory Limit: 1024 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

class TreeAnc {
private:
    vector<vector<int>> anc;
    int maxLog;
    vector<int> depth;

public:
    TreeAnc(vector<vector<int>>& adj, int root = 1) {
        int n = adj.size();
        maxLog = __lg(n)+1;
        anc.resize(maxLog, vector<int>(n, -1));
        
        //bfs
	        depth.assign(n,-1);
        vector<int> st;
        st.push_back(root);
        depth[root] = 0;
        while (!st.empty()) {
            int node = st.back();
            st.pop_back();
            for (int son : adj[node]) {
                if (depth[son] == -1) {
                    depth[son] = depth[node] + 1;
                    anc[0][son] = node;
                    st.push_back(son);
                }
            }
        }

        for (int i = 1; i < maxLog; i++) {
            for (int j = 0; j < n; j++) {
                if (anc[i-1][j] != -1) {
                    anc[i][j] = anc[i-1][anc[i-1][j]];
                }
            }
        }
    }

    int query(int p, int step) {
        if (step < 0) return -1;
        for (int i = 0; i < maxLog; i++) {
            if (step & (1ll << i)) {
                p = anc[i][p];
                if (p == -1) break;
            }
        }
        return p;
    }
    
    //0-based
    int deep(int p) {
    	return depth[p];
    }
};

void solve()
{
	int n,k;
	cin>>n>>k;
	
	vector adj(n+1,vector<int>(0));
	vector<int> fa(n+1,-1);
	for(int i=2;i<=n;i++) {
		cin>>fa[i];
		adj[fa[i]].push_back(i);
	}
	
	vector<array<int,3>> a(k+1);
	for(int i=1;i<=k;i++) {
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	
	TreeAnc anc(adj,1);
	vector<bool> mark(n+1);
	mark[1]=1;
	int ans=-1;
	
	for(int i=1;i<=k;i++) {
		auto [p,l,r]=a[i];
		if (mark[p]) {cout<<l<<'\n';return;}
		int lo=0,hi=anc.deep(p),res=-1,pos=-1;
		while (lo <= hi) {
			int mid=lo+hi>>1;
			int idx=anc.query(p,mid);
			if (mark[idx]) res=mid,pos=idx,hi=mid-1;
			else lo=mid+1;
		}
		int ed=anc.deep(pos)+(r-l+1);
		if (ed >= anc.deep(p)) {
			ans=l+res-1;
			break;
		}
		while (anc.deep(p) != ed) p=fa[p];
		while (p != pos) {
			mark[p]=1;
			p=fa[p];
		}
	}
	cout<<ans;
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









