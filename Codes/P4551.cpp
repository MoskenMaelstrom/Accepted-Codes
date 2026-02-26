// Problem: P4551 最长异或路径
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4551
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)



//无向树,求最长异或路径
#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
#define int long long
using namespace std;

const int N=2e6;
int trie[N][2];//01Trie

void solve()
{
	int n;
	cin>>n;
	vector adj(n+1,vector<array<int,2>>(0));
	for(int i=0;i<n-1;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	vector<int> dis(n+1,0);//记录每个点到0的异或和
	vector<bool> mark(n+1,0);
	auto dfs=[&](this auto &&self,int x,int res) -> void {
		mark[x]=1;
		for(auto [v,w] : adj[x]) {
			if (mark[v] == 0) {
				dis[v]=res^w;
				self(v,res^w);
			}
		}
		mark[x]=0;
	};
	dfs(1,0);
	
	
	int cnt=1;
	auto insert=[&](int x) -> void {
		int p=1;//从1这个位置开始找
		for(int i=31;i>=0;i--) {
			int num=((x>>i)&1);
			if (trie[p][num] == 0) trie[p][num]=++cnt;
			p=trie[p][num];
		}
	};
	for(int i=1;i<=n;i++) {
		insert(dis[i]);
	}
	
	
	
	auto work=[&](int x) -> int {
		int p=1;
		int res=0;
		for(int i=31;i>=0;i--) {
			int num=((x>>i)&1);//取第i位
			if (trie[p][num^1] >= 1) {
				res+=(1<<i);
				p=trie[p][num^1];
			}
			else p=trie[p][num];
		}
		return res;
	};
	int ans=0;
	for(int i=1;i<=n;i++) {
		ans=max(ans,work(dis[i]));
	}
	cout<<ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









