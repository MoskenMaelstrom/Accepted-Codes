#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int inf=1e6;
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n);
	vector<int> ans(n,-1);
	multiset<array<int,3>> st;//{t,id,1}
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<k;i++) {
		int t,sc;
		cin>>t>>sc;
		while (sc--) {
			int id;
			cin>>id;
			id--;
			st.insert({t,id,inf});
		}
	}
	
	vector adj(n,vector<array<int,2>>(0));//{long,id}
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		adj[u].push_back({w,v});
	}
	
	for(int i=0;i<n;i++) {
		if (a[i] == 0) st.insert({0,i,1});
	}
	
	while (!st.empty()) {
		auto [t,id,val]=*st.begin();
		// cout<<t<<" "<<id<<" "<<val<<endl;
		st.erase(st.begin());
		if (ans[id] != -1) continue;
		a[id]-=val;
		if (a[id] <= 0) {
			ans[id]=t;
			for(auto [t1,id1] : adj[id]) {
				st.insert({t+t1,id1,1});
			}
		}
	}
	
	for(auto e1 : ans) cout<<e1<<" ";
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









