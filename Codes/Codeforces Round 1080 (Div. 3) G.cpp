// Problem: G. Idiot First Search and Queries
// Contest: Codeforces - Codeforces Round 1080 (Div. 3)
// URL: https://codeforces.com/contest/2195/problem/G
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> L(n+1),R(n+1);
	for(int i=1;i<=n;i++) {
		int u,v;
		cin>>u>>v;
		L[i]=u;
		R[i]=v;
	}
	
	vector<int> cnt(n+1);
	vector<int> ord;
	vector<int> st(n+1);
	function<void(int)> dfs=[&](int u) {
		st[u]=ord.size();
		ord.push_back(u);
		
		if (L[u] == 0) return;
		dfs(L[u]);
		ord.push_back(u);
		dfs(R[u]);
		ord.push_back(u);
		cnt[u]=4+cnt[L[u]]+cnt[R[u]];
	};
	dfs(1);
	
	vector to(n+1,vector<int>(20));
	vector sum(n+1,vector<int>(20));
	function<void(int,int)> dfs2=[&](int u,int p) {
		to[u][0]=p;
		sum[u][0]=cnt[u]+1;
		for(int i=1;i<20;i++) {
			to[u][i]=to[to[u][i-1]][i-1];
			sum[u][i]=sum[u][i-1]+sum[to[u][i-1]][i-1];
		}
		if (L[u]) {
			dfs2(L[u],u);
			dfs2(R[u],u);
		}
	};
	dfs2(1,0);
	
	while (q--) {
		int u,k;
		cin>>u>>k;
		for(int i=19;i>=0;i--) {
			if (sum[u][i] <= k) {
				k-=sum[u][i];
				u=to[u][i];
			}
		}
		cout<<ord[st[u]+k]<<" ";
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







