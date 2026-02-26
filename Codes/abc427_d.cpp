// Problem: D - The Simple Game
// Contest: AtCoder - Panasonic Programming Contest 2025（AtCoder Beginner Contest 427）
// URL: https://atcoder.jp/contests/abc427/tasks/abc427_d
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
	k<<=1;
	string s;
	cin>>s;
	vector<bool> vec(n);
	for(int i=0;i<n;i++) {
		vec[i]=(s[i] == 'A' ? 1 : 0);
	}
	
	vector adj(n,vector<int>(0));
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
	}
	
	map<array<int,3>,int> mp;
	auto dfs=[&](auto self,int mask,int step,int u) -> bool {
		if (mp.count({mask,step,u})) return mp[{mask,step,u}];
		if (step == 0) return vec[u];
		if (mask) { //Alice
			bool ok=0;
			for(auto v : adj[u]) {
				ok|=self(self,0,step-1,v);
			}
			return mp[{mask,step,u}]=ok;
		}
		else {
			bool ok=1;
			for(auto v : adj[u]) {
				ok&=self(self,1,step-1,v);
			}
			return mp[{mask,step,u}]=ok;
		}
	};
	
	if (dfs(dfs,1,k,0)) cout<<"Alice\n";              
	else cout<<"Bob\n";
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









