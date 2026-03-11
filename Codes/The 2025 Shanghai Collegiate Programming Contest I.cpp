// Problem: I. 真相
// Contest: Codeforces - The 2025 Shanghai Collegiate Programming Contest
// URL: https://codeforces.com/gym/105992/problem/I
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector adj(n,vector<int>(0));
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> siz(n+1,1);
	function<void(int,int)> dfs1=[&](int u,int fa) {
		for(auto v : adj[u]) {
			if (v == fa) continue;
			dfs1(v,u);
			siz[u]+=siz[v];
		}
	};
	dfs1(0,0);
	
	vector dp(n,vector<int>(n+1));
	function<void(int,int)> dfs2=[&](int u,int fa) {
		vector<int> cnt(n+1);
		cnt[0]=1;
		int cur=0;
		for(auto v : adj[u]) {
			if (v == fa) continue;
			dfs2(v,u);
			vector<int> ncnt(n+1);
			for(int i=0;i<=cur;i++) {
				for(int j=0;j<=siz[v];j++) {
					(ncnt[i+j]+=cnt[i]*dp[v][j]%p)%=p;
				}
			} 
			cnt=ncnt;
			cur+=siz[v];
		}
		for(int i=0;i<=n;i++){
            if (i == a[u]) dp[u][i]=a[u] == 0 ? 0 : cnt[i-1];
            else dp[u][i]=cnt[i];
        }
	};
	dfs2(0,0);
	
	int ans=0;
	for(int i=0;i<=n;i++) (ans+=dp[0][i])%=p;
	cout<<ans<<"\n";
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







