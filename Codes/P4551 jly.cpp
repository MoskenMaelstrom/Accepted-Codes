// Problem: P4551 最长异或路径
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4551
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

constexpr int N=1e5*31;
int tot;
int trie[N][2];
int cnt[N];

int newNode() {
	int x=++tot;
	trie[x][0]=trie[x][1]=0;
	cnt[x]=0;
	return x;
}

void init() {
	tot=0;
	newNode();
}

void add(int x,int t) {
	int o=1;
	for(int i=30;i>=0;i--) {
		int &p=trie[o][x>>i&1];
		if (p == 0) p=newNode();
		o=p;
		cnt[o]+=t;
	}
}

int query(int x) {
	int o=1;
	int ans=0;
	for(int i=30;i>=0;i--) {
		int d=x>>i&1;
		if (cnt[trie[o][d^1]]) {
			ans|=1<<i;
			d^=1;
		}
		o=trie[o][d];
	}
	return ans;
}

void solve()
{
	int n;
	cin>>n;
	vector adj(n,vector<array<int,2>>(0));
	for(int i=0;i<n-1;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	vector<int> dis(n);
	vector<bool> mark(n);
	auto dfs=[&](this auto &&self,int x,int res) -> void {
		mark[x]=1;
		for(auto [v,w] : adj[x]) {
			if (mark[v]) continue;
			dis[v]=res^w;
			self(v,res^w);
		}
	};
	dfs(1,0);
	
	init();
	for(int i=0;i<n;i++) {
		add(dis[i],1);
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		ans=max(ans,query(dis[i]));
	}
	cout<<ans<<endl;
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









