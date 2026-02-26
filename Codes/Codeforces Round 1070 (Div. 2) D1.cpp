// Problem: D. Fibonacci Paths
// Contest: Codeforces - Codeforces Round 1070 (Div. 2)
// URL: https://codeforces.com/contest/2176/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
using ull=unsigned long long;
using namespace std;

const int p=998244353;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<array<int,3>> edge(m);
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		edge[i]={a[u]+a[v],u,v};
	}
	ranges::sort(edge,greater<array<int,3>>());
	
	int ans=0;
	vector<map<int,int>> dp(n);
	for(auto [w,u,v] : edge) {
		int res=dp[v][w]+1;
		dp[u][a[v]]+=res;
		dp[u][a[v]]%=p;
		ans+=res;
		ans%=p;
	}
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







