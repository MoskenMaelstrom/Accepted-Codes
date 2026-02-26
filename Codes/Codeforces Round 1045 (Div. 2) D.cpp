// Problem: D. Sliding Tree
// Contest: Codeforces - Codeforces Round 1045 (Div. 2)
// URL: https://codeforces.com/contest/2134/problem/D
// Memory Limit: 256 MB
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

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector du(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		du[u].push_back(v);
		du[v].push_back(u);
	}
	
	int ok=1;
	for(int i=0;i<n;i++) {
		if (du[i].size() > 2) ok=0;
	}
	
	if (ok) cout<<"-1\n";
	else {
		vector<int> dist(n),last(n),mark(n);
		auto dfs=[&](this auto &&self,int u) -> void {
			mark[u]=1;
			for(auto e1 : du[u]) {
				if (mark[e1]) continue;
				last[e1]=u;
				dist[e1]=dist[u]+1;
				self(e1);
			}
		};
		dfs(0);
		int p1=0,maxn=0;
		for(int i=0;i<n;i++) {
			if (maxn < dist[i]) maxn=dist[i],p1=i;
		}
		
		dist.assign(n,0);
		last.assign(n,-1);
		mark.assign(n,0);
		dfs(p1);
		
		int p2=0,maxnn=0;
		for(int i=0;i<n;i++) {
			if (maxnn < dist[i]) maxnn=dist[i],p2=i;
		}
		
		vector<int> dia;
		int p=p2;
		while (p != p1) {
			dia.push_back(p);
			p=last[p];
		}
		
		vector<bool> idx(n);
		for (auto e1 : dia) idx[e1]=1;
		for(auto e1 : dia) {
			if (du[e1].size() > 2) {
				
				int a,b=e1,c;
				for(auto e2 : du[e1]) {
					if (idx[e2]) a=e2;
					if (!idx[e2]) c=e2;
				}
				
				cout<<a+1<<' '<<b+1<<' '<<c+1<<'\n';
				return;
			}
		}
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









