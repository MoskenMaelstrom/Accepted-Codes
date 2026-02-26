// Problem: P8435 【模板】点双连通分量
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8435
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

struct VBCC {
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn,low;
    vector<bool> flag;
    vector<vector<int>> comp;
    int cur,cnt;

    VBCC() {}
    VBCC(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        stk.clear();
        dfn.assign(n, -1);
        low.resize(n);
        flag.assign(n, false);
        comp.clear();
        cur = 0;
        cnt = 0;
    }

    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int x, int p) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        int cnt0 = 0;

        for (auto y : adj[x]) {
            if (y == p) continue;

            if (dfn[y] != -1) {
                low[x] = min(low[x], dfn[y]);
            } else {
                cnt0++;
                dfs(y, x);
                low[x] = min(low[x], low[y]);
                if (low[y] >= dfn[x]) {
                    if (p != -1) flag[x] = true;
                    cnt++;
                    comp.emplace_back();
                    vector<int>& bcc = comp.back();
                    int z;
                    do {
                        z = stk.back();
                        stk.pop_back();
                        bcc.push_back(z);
                    } while (z != y);
                    
                    bcc.push_back(x);
                }
            }
        }
        
        if (p == -1 && cnt0 > 1) flag[x] = true;
        if (p == -1 && cnt0 == 0) {
            cnt++;
            comp.emplace_back();
            comp.back().push_back(x);
            stk.pop_back();
        }
    }

    void work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                stk.clear();
                dfs(i, -1);
            }
        }
    }
};

void solve()
{
	int n,m;
	cin>>n>>m;
	VBCC vbcc(n);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		vbcc.add(u,v);
	}
	
	vbcc.work();
	auto comp=vbcc.comp;
	cout<<comp.size()<<"\n";
	for(int i=0;i<comp.size();i++) {
		cout<<comp[i].size()<<" ";
		for(auto v : comp[i]) {
			cout<<v+1<<" ";
		}
		cout<<"\n";
	}
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







