#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector adj(n+1,vector<int>(0));
	for(int i=1;i<=n;i++) {
		int u;
		cin>>u;
		adj[u].push_back(i);
	}
	if (n == 1) {
		cout<<"0 yes\n1";
		return;
	}
	for(int i=1;i<=n;i++) ranges::sort(adj[i]);
	set<int> st;
	for(int i=1;i<=n;i++) st.insert(adj[i].size());
	cout<<*(--st.end())<<" ";
	if (st.size() == 2) cout<<"yes\n";
	else cout<<"no\n";
	
	bool ok=1;
	auto dfs=[&](auto&& self,int u) -> void {
		if (ok) {cout<<u;ok=0;}
		else cout<<" "<<u;
		for(auto v : adj[u]) {
			self(self,v);
		}
	};
	
	dfs(dfs,adj[0][0]);
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







