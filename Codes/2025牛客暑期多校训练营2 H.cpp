// Problem: Highway Upgrade
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108299/H
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

const int inf=1e18;
vector<int> dijkstra(vector<vector<array<int,2>>> &adj, int start) {
    int n = adj.size();
    vector<int> dis(n, inf);
    dis[start] = 0;
    set<array<int,2>> st;
    st.insert({0, start});
    while (!st.empty()) {
        auto [cdis, u] = *st.begin();
        st.erase(st.begin());
        if (cdis > dis[u]) continue;
        for (auto &[v, w] : adj[u]) {
            int ndis = dis[u] + w;
            if (ndis < dis[v]) {
                dis[v] = ndis;
                st.insert({ndis, v});
            }
        }
    }
    return dis;
}

double cross(const array<int,2> &a, const array<int,2> &b, const array<int,2> &c) {
	return i128(b[0]-a[0])*i128(c[1]-a[1])-i128(b[1]-a[1])*i128(c[0]-a[0]);
}

double dis(const array<int,2> &a, const array<int,2> &b) {
	return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

vector<array<int,2>> andrew(vector<array<int,2>> &a) {
	ranges::sort(a);
	vector<array<int,2>> l,h;
	for(auto p : a) {
		while (l.size() > 1 and cross(l[l.size()-2],l.back(),p) <= 0) l.pop_back();
		while (h.size() > 1 and cross(h[h.size()-2],h.back(),p) >= 0) h.pop_back();
		l.push_back(p);
		h.push_back(p);
	}
	// ranges::reverse(h);
	// h.insert(h.end(),l.begin()+1,l.end()-1);
	return l;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector adj1(n,vector<array<int,2>>(0));
	vector adj2(n,vector<array<int,2>>(0));
	vector<array<int,4>> edge(m);
	
	for(int i=0;i<m;i++) {
		int u,v,t,w;
		cin>>u>>v>>t>>w;
		u--,v--;
		edge[i]={u,v,t,w};
		adj1[u].push_back({v,t});
		adj2[v].push_back({u,t});
	}
	
	auto d1=dijkstra(adj1,0);
	auto d2=dijkstra(adj2,n-1);
	
	vector<array<int,2>> vec;
	for(auto [u,v,t,w] : edge) {
		if (d1[u] < inf and d2[v] < inf) vec.push_back({w,d1[u]+t+d2[v]});
	}
	auto hull=andrew(vec);
	
	int q;
	cin>>q;
	while (q--) {
		int k;
		cin>>k;
		auto calc=[&](auto a,int k) {	
			return a[1]-k*a[0];
		};
		
		int lo=0,hi=hull.size()-2;
		while (lo <= hi) {
			int mid=lo+hi>>1;
			if (calc(hull[mid],k) > calc(hull[mid+1],k)) lo=mid+1;
			else hi=mid-1;
		}
		cout<<calc(hull[lo],k)<<'\n';
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









