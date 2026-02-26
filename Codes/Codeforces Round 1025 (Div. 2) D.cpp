// Problem: D. D/D/D
// Contest: Codeforces - Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/contest/2109/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

vector<int> dijkstra(vector<vector<array<int,2>>> &adj, int start) {
    int n = adj.size();
    int inf = 0x3f3f3f3f3f3f3f3fll;
    vector<int> dis(n, inf);
    dis[start] = 0;
    set<array<int,2>> st;
    st.insert({0, start});
    while (!st.empty()) {
        auto [cdis, u] = *st.begin();
        st.erase(st.begin());
        if (cdis > dis[u]) continue;
        for (auto &[v, weight] : adj[u]) {
            int ndis = dis[u] + weight;
            if (ndis < dis[v]) {
                dis[v] = ndis;
                st.insert({ndis, v});
            }
        }
    }
    return dis;
}

void solve()
{
	int n,m,l;
	cin>>n>>m>>l;
	vector<int> vec(l);
	for(int i=0;i<l;i++) cin>>vec[i];
	vector adj(2*n,vector<array<int,2>>(0));
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back({v+n,1});
		adj[v].push_back({u+n,1});
		adj[u+n].push_back({v,1});
		adj[v+n].push_back({u,1});
	}
	auto dis=dijkstra(adj,0);
	
	vector<int> a0,a1;
	for(auto e1 : vec) {
		if (e1%2 == 0) a0.push_back(e1);
		else a1.push_back(e1);
	}
	ranges::sort(a0);
	ranges::sort(a1);
	int sum=0,sum0=0,sum1=0;
	for(auto e1 : vec) sum+=e1;
	if (sum%2 == 0) {
		sum0=sum;
		if (!a1.empty()) sum1=sum0-a1[0];
	}
	else {
		sum1=sum;
		if (!a1.empty()) sum0=sum1-a1[0];
	}
	
	for(int i=0;i<n;i++) {
		if (i == 0 or dis[i] <= sum0 or dis[i+n] <= sum1) cout<<"1";
		else cout<<"0";
	}
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









