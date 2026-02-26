// Problem: C. Trapmigiano Reggiano  C. 特拉皮米亚诺-雷吉亚诺
// Contest: Codeforces - Codeforces Round 1007 (Div. 2)
// URL: https://codeforces.com/contest/2071/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,st,en;
	cin>>n>>st>>en;
	st--;
	en--;
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//bfs
	queue<int> q;
	vector<int> ans;
	vector<bool> flag(n,0);
	q.push(en);
	ans.push_back(en);
	flag[en]=1;
	while (!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(auto ele : adj[cur]) {
			if (flag[ele]) continue;
			q.push(ele);
			ans.push_back(ele);
			flag[ele]=1;
		}
	}
	ranges::reverse(ans);
	for(auto ele : ans) cout<<ele+1<<" ";	
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









