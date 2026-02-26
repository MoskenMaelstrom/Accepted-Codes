// Problem: G. Welcome to Join the Online Meeting!
// Contest: Codeforces - 2024 China Collegiate Programming Contest (CCPC) Harbin Onsite (The 3rd Universal Cup. Stage 14: Harbin)
// URL: https://codeforces.com/gym/105459/problem/G
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<bool> ok(n+1,1);
	for(int i=0;i<k;i++) {
		int num;
		cin>>num;
		ok[num]=0;
	}
	
	vector adj(n+1,vector<int>(0));
	while (m--) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int root=-1;
	for(int i=1;i<=n;i++) {
		if (ok[i]) root=i;
	}
	if (root == -1) {cout<<"No\n";return;}
	
	vector<vector<int>> ans;
	
	vector<bool> mark(n+1);
	queue<int> q;
	q.push(root);mark[root]=1;
	
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		if (!ok[u]) continue;
		
		int cnt=0;
		vector<int> vec;
		vec.push_back(u);
		vec.push_back(0);
		for(auto v : adj[u]) {
			if (mark[v]) continue;
			cnt++;
			mark[v]=1;
			vec.push_back(v);
			q.push(v);
		}
		if (cnt == 0) continue;
		vec[1]=cnt;
		ans.push_back(vec);
	}
	
	bool can=1;
	for(int i=1;i<=n;i++) {
		if (!mark[i]) can=0;
	}
	
	if (can) {
		cout<<"Yes\n";
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++) {
			for(auto e1 : ans[i]) cout<<e1<<" ";
			cout<<"\n";
		}
	}
	else cout<<"No\n";
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









