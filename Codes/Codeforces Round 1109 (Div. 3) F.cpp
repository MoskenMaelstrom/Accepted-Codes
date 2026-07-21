// Problem: F. Anya Loves Trees!
// Contest: Codeforces - Codeforces Round 1109 (Div. 3)
// URL: https://codeforces.com/contest/2244/problem/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

bool check(vector<int>& vec) {
	int cnt=0;
	int n=vec.size();
	for(int i=0;i<n;i++) {
		if (vec[i] > vec[(i+1)%n]) cnt++;
	}
	return cnt <= 1;
}

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector adj(n+1,vector<int>(0));
	for(int i=2;i<=n;i++) {
		int u;
		cin>>u;
		adj[u].push_back(i);
	}
	for(auto v : adj) ranges::sort(v);
	
	vector<int> mx(n+1,-inf),mn(n+1,inf);
	vector<int> cnt(n+1);
	
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]) mx[i]=mn[i]=a[i],cnt[i]=1;
	}
	
	bool ok=1;
	auto dfs=[&](auto&& self,int u) -> void {
		if (!ok) return;
		vector<int> vec;
		for(auto v : adj[u]) {
			if (a[v] == 0) self(self,v);
			if (!ok) return;
			vec.push_back(mn[v]);
			cnt[u]+=cnt[v];
			mx[u]=max(mx[u],mx[v]);
			mn[u]=min(mn[u],mn[v]);
		}
		if (mx[u]-mn[u]+1 != cnt[u]) ok=0;
		if (!check(vec)) ok=0;
	};
	dfs(dfs,1);
	
	if (ok) cout<<"YES\n";
	else cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







